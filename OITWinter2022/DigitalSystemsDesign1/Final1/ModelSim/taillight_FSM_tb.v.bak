`timescale 1ns / 1ps

module receiver_tb();

reg clk;
reg data_in;

wire [7:0] data_out;
wire [1:0] state;
wire [3:0] count, clkCount;
wire parity, valid;

receiver			U1(clk, data_in, data_out);

initial
	begin
		clk <= 0;
		data_in <= 1;

		#5 data_in <= 0;
		#160 data_in <= 1;
		
		#1360 data_in <= 0;
		#170 data_in <= 1;

	end

	always
	#5 clk <= ~clk;

endmodule
