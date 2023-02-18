`timescale 1ns / 1ps

module display_tb();

reg [3:0] hex;

wire [6:0] display;

bcd_to_decimal			U1(hex, display);

initial
	begin
		hex <= 4'b000;
	end

	always
		#20 hex <= hex + 1;

endmodule
