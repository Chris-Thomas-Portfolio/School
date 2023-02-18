`timescale 1ns / 1ps

module sel_tb ();

reg clk;

wire [1:0] sel;

control_generator U1(clk, sel);

// Handle the Clock
	always
		#5 clk <= ~clk;
		
initial
	begin
			clk <= 0;
	end
	
endmodule