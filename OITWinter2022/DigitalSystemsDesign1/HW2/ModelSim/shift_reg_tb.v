`timescale 1ns / 1ps

module shift_reg_tb();

reg [3:0] data;
reg clk, load, shr, clr;

wire a;

shift_reg			U1(data, clk, load, shr, clr, a);

initial
	begin
		data <= 4'b1010;
		clk <= 0;
		load <= 0;
		shr <= 0;
		clr <= 0;

		#10 load <= 1;
		#10 load <= 0;
		#10 shr <= 1;
		#60 shr <= 0;
		#10 clr <= 1;
		#10 clr <= 0;
	end

	always
		#5 clk <= ~clk;

endmodule
