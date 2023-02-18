//   Author: Chris Thomas
//   Lab: Lab03
//   Project: Multiplexed Display
//   File Name: mux_display.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Instantiates modules.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module mux_display(
input CLOCK_50_MHz,
input [15:0] bcd_out,
output [6:0] display,
output [3:0] dis_sel
);

wire [6:0] ones;
wire [6:0] tens;
wire [6:0] hundreds;
wire [6:0] thousands;

wire divided_clock_2kHz;
wire [1:0] sel;

clk_divider 	 	 #(12500) U1(CLOCK_50_MHz, divided_clock_2kHz);
control_generator				 U2(divided_clock_2kHz, sel);
demux 							 U3(divided_clock_2kHz, sel, dis_sel);
bcd_to_decimal					 U4(bcd_out[3:0], ones);
bcd_to_decimal					 U5(bcd_out[7:4], tens);
bcd_to_decimal					 U6(bcd_out[11:8], hundreds);
bcd_to_decimal					 U7(bcd_out[15:12], thousands);
mux_case							 U8(ones, tens, hundreds, thousands, sel, divided_clock_2kHz, display);

endmodule