`timescale 1ns / 1ps

module bcd_tb();

reg [15:0] bin;

wire [19:0] bcd;

binary_to_bcd		U1(bin, bcd);

initial
	begin
		bin 				<= 16'b0000000000000000;
	end
	
	always
		#5 bin <= bin + 1;
	
endmodule