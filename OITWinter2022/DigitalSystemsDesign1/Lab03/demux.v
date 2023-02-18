//   Author: Chris Thomas
//   Lab: Lab03
//   Project: Multiplexed Display
//   File Name: demux.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Picks which digit to light up.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module demux(
	input clk,
	input [1:0] sel,
	output reg [3:0] dis_sel
);

always @(posedge clk)
	begin
		case(sel)
			2'b00 : dis_sel <= 4'b1110;
			2'b01 : dis_sel <= 4'b1101;
			2'b10 : dis_sel <= 4'b1011;
			2'b11 : dis_sel <= 4'b0111;
			default : dis_sel <= 4'bzzzz;
		endcase
	end
endmodule