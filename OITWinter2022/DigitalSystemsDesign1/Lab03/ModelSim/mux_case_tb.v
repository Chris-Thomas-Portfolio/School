`timescale 1ns / 1ps

module mux_case_tb ();

reg clk;
reg [6:0] ones, tens, hundreds, thousands;
reg [1:0] sel;
wire [6:0] mout;

mux_case U1(ones, tens, hundreds, thousands, sel, clk, mout);

// Handle the Clock
	always
		#5 clk <= ~clk;
		
initial
	begin
			clk <= 0;
			ones <= 1;
			tens <= 10;
			hundreds <= 100;
			thousands <= 1000;
			sel <= 0;
	end
	
	always
		#10 sel <= sel + 1;
	
endmodule