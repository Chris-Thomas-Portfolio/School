//-----------------------------------------------------------------------------
//   University: Oregon Institute of Technology – CSET Department
//   Class: CST 231
//   Author: Chris Thomas
//   Lab: Lab 1
//   Project: 4-Bit Adder
//   File Name: Lab01.v
//   List of other files used: Adder 4-Bit.v, 7Seg.v, etc.
//-----------------------------------------------------------------------------
//   Description of the Code (1 - 5 lines)
//   The adder takes to binary values brought in by the switches and adds them
//	  together. The individual values as well as the result are displayed on the
//	  7-segment displays.
//-----------------------------------------------------------------------------
//   Date: 01/5/2022
//   Version: 1.0
//   Revision: Added cases for all 30 values - 1/12/2022
//-----------------------------------------------------------------------------
module Lab01(
input  [7:0] SW,
output [0:6] HEX0,
output [0:6] HEX1,
output [0:6] HEX2,
output [0:6] HEX3,
output [0:6] HEX4,
output [0:6] HEX5
);

wire [4:0] Q;

add 			   Add1   	(.a(SW[3:0]), .b(SW[7:4]), .result(Q));
bin7seg 		 	seg1 		(.bin(SW[3:0]), .display1(HEX0), .display10(HEX1));
bin7seg		   seg2	  	(.bin(SW[7:4]), .display1(HEX2), .display10(HEX3));
bin7seg		   seg3	  	(.bin(Q[4:0]), .display1(HEX4), .display10(HEX5));

endmodule
