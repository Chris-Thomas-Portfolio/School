`timescale 1ns / 1ps

module to_upper_tb();

reg clk, new_data;
reg [7:0 ]data_in;
wire [7:0] data_out;
wire transmit;
wire [3:0] count;

to_upper			U1(clk, data_in, new_data, data_out, transmit);

initial
	begin
		clk <= 0;
		new_data <= 0;
		data_in <= 97;

		#5 new_data <= 1;
		#5 new_data <= 0;
	end

	always
		#5 clk <= clk + 1;

endmodule
