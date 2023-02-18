`timescale 1ns / 1ps

module transmit_tb();

reg clk, but;
reg [7:0] data;

wire data_out;
wire [1:0] state;
wire [3:0] count;

transmit			U1(clk, but, data, data_out);

initial
	begin
		clk <= 0;
		but <= 0;
		data <= 8'b01010111;

		#5 but <= 1;
		#5 but <= 0;

	end

	always
	#5 clk <= ~clk;

endmodule
