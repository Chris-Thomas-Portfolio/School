//   Author: Chris Thomas
//   Lab: Lab03
//   Project: Multiplexed Display
//   File Name: control_generator.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Controls the mux_case and demux modules.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module control_generator(
	input clk,
	output reg[1:0] Sel
);

/*Init block for testbench*/
initial
	begin
		Sel <= 0;
	end
	
always @(posedge clk)
	begin
		Sel <= Sel + 1;
	end
	
endmodule