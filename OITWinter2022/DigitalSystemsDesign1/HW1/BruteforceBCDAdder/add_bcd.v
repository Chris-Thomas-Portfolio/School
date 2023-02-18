//   Author: Chris Thomas
//   Lab: HW 1 Question 2
//   Project: BFBCDAdder
//   File Name: add_bcd.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   This module uses brute force code to add two 4-bit BCD inputs.
//-----------------------------------------------------------------------------
//   Date: 02/02/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module add_bcd(
input [3:0] a,
input [3:0] b,
output reg cout,
output reg[3:0] s
);

always @(*)
	begin
		s <= (a + b) % 10;
		cout <= (a + b > 9);
	end
endmodule