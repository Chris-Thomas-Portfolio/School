//   Author: Chris Thomas
//   Lab: Lab03
//   Project: Multiplexed Display
//   File Name: multiplexed_display.v
//   List of other files used: clk_divider, counter, binary_to_bcd, mux_display
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Instantiates modules.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module multiplexed_display(
input CLOCK_50_MHz,
input [2:0] SW,
output [6:0] display,
output [3:0] dis_sel
);


wire divided_clock_100Hz;
wire [11:0] count;
wire [15:0] bcd_out;

clk_divider					U1(CLOCK_50_MHz, divided_clock_100Hz);
counter				#(12) U2(divided_clock_100Hz, SW[0], SW[1], SW[2], count);
binary_to_bcd		#(12)	U3(count, bcd_out);
mux_display 				U4(CLOCK_50_MHz, bcd_out, display, dis_sel);

endmodule