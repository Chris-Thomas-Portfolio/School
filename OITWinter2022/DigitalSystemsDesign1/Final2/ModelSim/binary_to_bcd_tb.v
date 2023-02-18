`timescale 1ns / 1ps

module binary_to_bcd_tb();

reg [15:0] bin;

wire [20:0] bcd;

binary_to_bcd		U1(bin, bcd);

initial
	begin
		bin 				<= 5'b00000;
	end

	always
		#5 bin <= bin + 1;

endmodule
