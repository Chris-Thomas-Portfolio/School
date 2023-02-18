//   Author: Chris Thomas
//   Lab: Lab03
//   Project: Multiplexed Display
//   File Name: mux_case.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Picks the correct value to be displayed.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module mux_case(
	input [6:0] ones,
	input [6:0] tens,
	input [6:0] hundreds,
	input [6:0] thousands,
	input [1:0] sel,
	input clk,
	output reg [6:0] mout
);

always @(posedge clk)
	begin
		case(sel)
			2'b00 : mout = ones;
			2'b01 : mout = tens;
			2'b10 : mout = hundreds;
			2'b11 : mout = thousands;
			default : mout = 4'bzzzz;
		endcase
	end
endmodule