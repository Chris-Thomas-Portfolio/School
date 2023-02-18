//   Author: Chris Thomas
//   Lab: HW2
//   Project: Bit serial adder
//   File Name: full_adder.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//  	full adder for serial adder.
//-----------------------------------------------------------------------------
//   Date: 03/01/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module full_adder(
	input a,
	input b,
	input cin,
	output cout,
	output sum
);

	assign {cout,sum} = a + b + cin;
	
endmodule
