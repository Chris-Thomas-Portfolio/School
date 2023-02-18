//   Author: Chris Thomas
//   Lab: Lab04
//   Project: Keypad
//   File Name: time.v
//   List of other files used: N/A 
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Once a key is pressed starts a timer of 15 seconds before terminating code
//	  entry.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module timer
	#(parameter LIMIT = 300)(
	input clk,
	input enable,
	output reg time_up
);

	reg [10:0] count;
	
initial
	begin
		time_up = 0;
	end
	
		always @(posedge clk)
			begin
				if (enable)
					begin
						if(count < LIMIT)			//at posedge of clk increment count if < SECOND
							begin
								count <= count + 1;
							end
						else
							begin
								count <= 0;
								time_up <= 1;
							end
					end
				else
					begin
						count <= 0;
						time_up <= 0;
					end
			end

endmodule
	