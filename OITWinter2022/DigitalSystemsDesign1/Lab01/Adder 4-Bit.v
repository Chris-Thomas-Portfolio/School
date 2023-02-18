//-----------------------------------------------------------------------------
//   University: Oregon Institute of Technology – CSET Department
//   Class: CST 231
//   Author: Chris Thomas
//   Lab: Lab 1
//   Project: 4-Bit Adder
//   File Name: Lab01.v
//   List of other files used: Adder 4-Bit.v, 7Seg.v, etc.
//-----------------------------------------------------------------------------
//   Description of the Code (1 - 5 lines)
//   This module handles the adding of the 2 input values.
//-----------------------------------------------------------------------------
//   Date: 01/5/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------

module add(
	input [3:0] a,
	input [3:0] b,
	output reg [4:0] result
);

	always @ (a or b)
	begin
			result = a + b;
	end

endmodule