//   Author: Chris Thomas
//   Lab: HW2
//   Project: Bit serial adder
//   File Name: adder_control.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   FSM to control serial adder.
//-----------------------------------------------------------------------------
//   Date: 03/01/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module adder_control(
	input clk,
	input reset,
	output reg load,
	output reg shr,
	output reg clr,
	output reg done
);

	reg [2:0] state;
	reg [2:0] count;
	
	parameter 	Idle	= 3'b000,
					Load	= 3'b001,
					Shift	= 3'b010,
					Clr	= 3'b011,
					Done	= 3'b100;
					
/*Init block for testbench*/
initial
	begin
		count <= 0;
		load <= 0;
		shr <= 0;
		clr <= 0;
		done <= 0;
		state <= Idle;
	end
	
	always @(posedge clk)
		begin
			if(reset)										//if reset is high go to state clr
				begin
					state <= Clr;
				end
			case(state)					
				Idle:
					begin
						load <= 0;
						shr <= 0;
						clr <= 0;
						done <= 0;
						state <= Load;						//Idle state resets values and then goes to Load state
					end
				Load:											//Load sets load high and then goes to Shift state
					begin
						load <= 1;
						state <= Shift;
					end
				Shift:										//Shift state shifts 4 values then goes to Done state
					begin
						load <= 0;
						if(count < 3)
							begin
								shr <= 1;
								count <= count + 1;
								state <= Shift;
							end
						else
							begin
								shr <= 0;
								count <= 0;
								state <= Done;
							end
					end
				Clr:											//Clr state sets clr high and returns to Idle state
					begin
						clr <= 1;
						state <= Idle;
					end
				Done:											//Done state sets done high and then returns to Idle
					begin
						done <= 1;
						state <= Idle;
					end
				default: state <= Idle;
			endcase
		end
		
endmodule
				