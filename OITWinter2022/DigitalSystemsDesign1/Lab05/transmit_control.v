//   Author: Chris Thomas
//   Lab: Lab05
//   Project: UART Transmit
//   File Name: transmit_control.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Create a state machine that works as a lockout for the button press.
//-----------------------------------------------------------------------------
//   Date: 03/5/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module transmit_control(
	input clk,
	input transmit,
	output reg but
);

reg [1:0] state;

parameter	Idle = 2'b00,
				Push = 2'b01,
				Wait = 2'b10;

initial
	begin
		but <= 0;
		state <= Idle;
	end
	
	always @(posedge clk)
		begin
			case(state)
				Idle:
					begin
						but <= 0;						//if the button is pushed moved to Push state
						if(!transmit)
							begin
								state <= Push;
							end
						else
							begin
								state <= Idle;			//else stay in Idle state
							end
					end
				Push:
					begin
						but <= 1;						//set the output to high
						state <= Wait;					//move to Wait state
					end
				Wait:
					begin
						but <= 0;					
						if(transmit)					//wait for button to be released so we dont get multiple inputs
							begin
								state <= Idle;
							end
						else
							begin
								state <= Wait;
							end
					end
			endcase
		end
endmodule