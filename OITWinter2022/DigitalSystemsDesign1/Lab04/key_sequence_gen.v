//   Author: Chris Thomas
//   Lab: Lab04
//   Project: Keypad
//   File Name: key_sequence_gen.v
//   List of other files used: N/A 
//-----------------------------------------------------------------------------
//   Description of the Code:
//   State machine that builds the sequence for the lock code.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module key_sequence_gen(
	input clk,
	input key_pressed,
	input times_up,
	input [3:0] key,
	output reg [15:0] sequence,
	output reg kp,
	output reg [15:0] temp,
	output reg new_seq
);

reg [2:0] state;

/* Creation of states*/
parameter Idle 		= 3'b000,
			 First 		= 3'b001,
			 Second 		= 3'b010,
			 Third 		= 3'b011,
			 Fourth 		= 3'b101,
			 Fifth		= 3'b110,
			 Output	 	= 3'b111;
			 
/*Initial block for testbench*/
initial
	begin
		sequence <= 0;
		kp <= 0;
		state <= Idle;
		temp <= 0;
		new_seq <= 0;
	end
	
	
	always @(posedge clk)
		begin
			if(times_up == 1)		//check for reset
				begin
					sequence <= 0;
					kp <= 0;
					temp <= 0;
					state = Output;
				end
			case(state)
				Idle:
					begin
						new_seq <= 0;
						temp <= 16'b1111111111111111;
						if(key_pressed)				//when key pressed insert value into sequence and move states 
							begin
								kp <= 1;
								state <= First;
							end
						else
							begin
								state <= Idle;
							end
					end
				First:
					begin
						if(key_pressed)				//when key pressed insert value into sequence and move states
							begin
								if(key == 4'b1111)
									begin
										state <= Output;
									end
								else if(key == 4'b1110)
									begin
										state <= Idle;
									end
								else
									begin
										temp[15:12] <= key;
										state <= Second;
									end
							end
					end
				Second:
					begin
						if(key_pressed)				//when key pressed insert value into sequence and move states
							begin
								if(key == 4'b1111)
									begin
										state <= Output;
									end
								else if(key == 4'b1110)
									begin
										state <= Idle;
									end
								else
									begin
										temp[11:8] <= key;
										state <= Third;
									end
							end
					end
				Third:
					begin
						if(key_pressed)				//when key pressed insert value into sequence and move states
							begin
								if(key == 4'b1111)
									begin
										state <= Output;
									end
								else if(key == 4'b1110)
									begin
										state <= Idle;
									end
								else
									begin
										temp[7:4] <= key;
										state <= Fourth;
									end
							end
					end
				Fourth:
					begin
						if(key_pressed)				//when key pressed insert value into sequence and move states
							begin
								if(key == 4'b1111)
									begin
										state <= Output;
									end
								else if(key == 4'b1110)
									begin
										state <= Idle;
									end
								else
									begin
										temp[3:0] <= key;
										state <= Fifth;
									end
							end
					end
				Fifth:
					begin
						if(key_pressed)
							begin
								if(key == 4'b1111)
									begin
										state <= Output;
									end
								else if(key == 4'b1110)
									begin
										state <= Idle;
									end
								else
									state <= Output;
							end
					end
				Output:							//set sequence to temp annd return to Idle state
					begin
						sequence <= temp;
						new_seq <= 1;
						kp <= 0;
						state <= Idle;
					end
		endcase
	end
endmodule

