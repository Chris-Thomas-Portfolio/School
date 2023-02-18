//   Author: Chris Thomas
//   Lab: Final2
//   Project: Final
//   File Name: clk_FSM.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Handles the states and count of the clock
//-----------------------------------------------------------------------------
//   Date: 03/13/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module clk_FSM(
	input clk,
	input reset,
	input set,
	input hour,
	input minute,
	output reg am,
	output reg [5:0] seconds,
	output reg [5:0] minutes,
	output reg [3:0] hours
);

reg [1:0] state;

parameter		Count 	= 2'b00,
					Minute	= 2'b01,
					Hour		= 2'b10;
					
/*Init block for testbench*/				
initial
	begin
		hours <= 12;
		seconds <= 0;
		minutes <= 0;
		am <= 1;
	end
					
	always @(posedge clk)								//always block for handling state changes
		begin
			if(hour == 0 && set == 0)
				begin
					state <= Hour;
				end
			else if(minute == 0 && set == 0)
				begin
					state <= Minute;
				end
			else
				begin
					state <= Count;
				end
		end
		
	always @(posedge clk)
		begin
			case(state)
				Count:
					begin
						if(~reset)							//if reset button is pushed set to default values
							begin
								seconds <= 0;
								minutes <= 0;
								hours <= 1;
								am <= ~am;
							end
						else if(seconds < 59)
							begin
								seconds <= seconds + 1;	//counter for seconds
							end
						else if(minutes < 59)
							begin
								seconds <= 0;
								minutes <= minutes + 1;		//counter for minutes
							end
						else if(hours < 12)
							begin
								if(hours == 11)
									begin
										seconds <= 0;
										minutes <= 0;
										hours <= hours + 1;		//counter for hours with am light control
										am <= ~am;
									end
								else
									begin
										seconds <= 0;
										minutes <= 0;
										hours <= hours + 1;
									end
							end
						else
							begin
								seconds <= 0;
								minutes <= 0;
								hours <= 1;
							end
					end
				Minute:
					begin
						if(minutes < 59)
							begin
								minutes <= minutes + 1;		//set minutes control
							end
						else
							begin
								minutes <= 0;
							end
					end
				Hour:
					begin
						if(hours < 12)
							if(hours == 11)
								begin
									hours <= hours + 1;		//set hours control
									am <= ~am;
								end
							else
								begin
									hours <= hours + 1;
								end
						else
							begin
								hours <= 1;
							end
					end
			endcase
		end

endmodule