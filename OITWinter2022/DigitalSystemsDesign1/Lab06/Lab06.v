//   Author: Chris Thomas
//   Lab: Lab06
//   Project: Tx Rx
//   File Name: Lab06.v
//   List of other files used: clk_divider.v, receiver.v, display.v, to_upper.v, transmit.v
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Builds the modules together for Rx and Tx.
//-----------------------------------------------------------------------------
//   Date: 03/11/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module Lab06(
	input CLOCK_50,
	input data_in,
	output [6:0] HEX0,
	output [6:0] HEX1,
	output data
);

wire clk, clk2;
wire [7:0] data_out;
wire new_data;
wire [7:0] upper;
wire transmit;

clk_divider		#(163) U1(CLOCK_50, clk);
clk_divider		#(2500)U2(CLOCK_50, clk2);
receiver			   	 U3(clk, data_in, data_out, new_data);
display					 U4(data_out[3:0], HEX0);
display					 U5(data_out[7:4], HEX1);
to_upper					 U6(clk, data_out, new_data, upper, transmit);
transmit					 U7(clk2, transmit, upper, data);

endmodule