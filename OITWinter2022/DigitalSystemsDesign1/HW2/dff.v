//   Author: Chris Thomas
//   Lab: HW2
//   Project: Bit serial adder
//   File Name: dff.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Flip-flop for holding carry out bit for serial adder.
//-----------------------------------------------------------------------------
//   Date: 03/01/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module dff(
	input d,
	input clk,
	input clr,
	output reg q
);

initial 
	begin
		q = 1'b0;
	end
	
always @(posedge clk)
	begin
		if(clr)
			begin
				q <= 0;
			end
		else
		begin
			q <= d;
		end
	end
endmodule