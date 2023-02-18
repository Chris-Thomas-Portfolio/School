//   Author: Chris Thomas
//   Lab: Final2
//   Project: Final
//   File Name: Final2.v
//   List of other files used: clk_FSM.v, clk_divider.v, binary_to_bcd.v, seven_seg.v
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Connects all the modules for full design.
//-----------------------------------------------------------------------------
//   Date: 03/13/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module Final2(
	input CLOCK_50,
	input reset,
	input set,
	input hour,
	input minute,
	output [6:0] HEX0,
	output [6:0] HEX1,
	output [6:0] HEX2,
	output [6:0] HEX3,
	output [6:0] HEX4,
	output [6:0] HEX5,
	output LEDR
);

wire clk;
wire [5:0] seconds;
wire [5:0] minutes;
wire [3:0] hours;
wire [7:0] seconds_out;
wire [7:0] minutes_out;
wire [7:0] hours_out;

clk_divider				#(25000000)	U1(CLOCK_50, clk);
clk_FSM									U2(clk, reset, set, hour, minute, LEDR, seconds, minutes, hours);
binary_to_bcd			#(6)			U3(seconds, seconds_out);
binary_to_bcd			#(6)			U4(minutes, minutes_out);
binary_to_bcd			#(4)			U5(hours, hours_out);
seven_seg								U6(seconds_out[3:0], HEX0);
seven_seg								U7(seconds_out[7:4], HEX1);
seven_seg								U8(minutes_out[3:0], HEX2);
seven_seg								U9(minutes_out[6:4], HEX3);
seven_seg								U10(hours_out[3:0], HEX4);
seven_seg								U11(hours_out[7:4], HEX5);

endmodule