//   Author: Chris Thomas
//   Lab: Final1
//   Project: Final
//   File Name: Final1.v
//   List of other files used: clk_divider.v, taillight_FSM.v
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Creates the system to control the taillights.
//-----------------------------------------------------------------------------
//   Date: 03/12/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module Final1(
	input CLOCK_50,
	input [3:0] SW,
	output [5:0] LEDR
);

wire clk;

clk_divider				#(25000000)U1(CLOCK_50, clk);
taillight_FSM			U2(clk, SW[0], SW[1], SW[2], SW[3], LEDR);




endmodule