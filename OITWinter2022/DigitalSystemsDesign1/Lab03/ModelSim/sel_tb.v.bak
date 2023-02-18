`timescale 1ns / 1ps

module testbench ();

reg clk, reset_n, enable;
wire [15:0] count;

counter U1(clk, reset_n, enable, count);

// Handle the Clock
	always
		#5 clk <= ~clk;
		
initial
	begin
			reset_n <= 0;
			enable  <= 0;
			clk	  <= 0;
			
			#10 reset_n <= 1;
	end
	
endmodule