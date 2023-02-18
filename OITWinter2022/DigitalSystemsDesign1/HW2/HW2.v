//   Author: Chris Thomas
//   Lab: HW2
//   Project: Bit serial adder
//   File Name: HW2.v
//   List of other files used: full_adder.v, shift_reg.v, adder_control.v, dff.v
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Creates a serial adder.
//-----------------------------------------------------------------------------
//   Date: 03/01/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module HW2(
	input [3:0] DATAa,
	input [3:0] DATAb,
	input clk,
	input reset,
	output [3:0] s
);

wire a, b, load, shr, clr, cin, cout, done;

full_adder		U1(a, b, cin, cout, s);
adder_control	U2(clk, reset, load, shr, clr, done);
shift_reg		U3(DATAa, clk, load, shr, clr, a);
shift_reg		U4(DATAb, clk, load, shr, clr, b);
dff				U5(cout, clk, clr, cin);


endmodule