`timescale 1ns / 1ps

module adder_control_tb();

reg clk, reset;

wire load, shr, clr, done;

adder_control			U1(clk, reset, load, shr, clr, done);

initial
	begin
		reset <= 0;
		clk <= 0;
		#5 reset <= 1;
		#5 reset <= 0;
	end

	always
		#5 clk <= ~clk;

endmodule
