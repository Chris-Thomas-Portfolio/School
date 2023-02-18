//   Author: Chris Thomas
//   Lab: Lab05
//   Project: Serial Communication
//   File Name: Lab05.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Top level for serial transmission.
//-----------------------------------------------------------------------------
//   Date: 03/5/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module Lab05(
	input CLOCK_50,
	input [7:0] SW,
	input KEY,
	output GPIO_0
);

wire clk, but;

clk_divider			#(2500)	U1(CLOCK_50, clk);
transmit_control				U2(clk, KEY, but);
transmit							U3(clk, but, SW, GPIO_0);


endmodule