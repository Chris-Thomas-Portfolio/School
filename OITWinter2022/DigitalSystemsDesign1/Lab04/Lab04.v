//   Author: Chris Thomas
//   Lab: Lab04
//   Project: Keypad
//   File Name: Lab04.v
//   List of other files used: clk_divider, timer, key_scanner, display, 
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Creates instances of all the modules needed.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module Lab04(
	input clk_50MHz,
	input [3:0] columns,
	output [3:0] rows,
	output [6:0] HEX0,
	output [6:0] HEX1,
	output [6:0] HEX2,
	output [6:0] HEX3,
	output [1:0] LEDR
);

wire clk_20Hz;
wire time_up_15;
wire [3:0] key;
wire [15:0] sequence;
wire [15:0] temp;
wire kp;
wire start_time;
wire time_up_5;
wire new_seq;


clk_divider			 #(1250000) U1(clk_50MHz, clk_20Hz);
key_scanner						 	U2(clk_20Hz, columns, rows, key, key_pressed);
key_sequence_gen					U3(clk_20Hz, key_pressed, time_up_15, key,sequence, kp, temp, new_seq);
timer							 		U4(clk_20Hz, kp, time_up_15);
display								U5(temp[3:0], HEX0);
display								U6(temp[7:4], HEX1);
display								U7(temp[11:8], HEX2);
display								U8(temp[15:12], HEX3);
sequence_check						U9(clk_20Hz, time_up_5, sequence, new_seq, LEDR[0], LEDR[1], start_time);
timer						 #(100)	U10(clk_20Hz, start_time, time_up_5);

endmodule