//   Author: Chris Thomas
//   Lab: Lab05Part2
//   Project: Serial Communication
//   File Name: Lab05Part2.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Top level for serial transmission.
//-----------------------------------------------------------------------------
//   Date: 03/9/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module Lab05Part2(
	input CLOCK_50,
	input KEY,
	output GPIO_0

);

wire clk, but;

clk_divider			#(2500)	U1(CLOCK_50, clk);
transmit_control				U2(clk, KEY, but);
transmit							U3(clk, but, GPIO_0);


endmodule