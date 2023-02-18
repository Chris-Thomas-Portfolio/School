`timescale 1ns / 1ps

module counter_tb ();

reg clk, reset_n, enable, up_down;
wire [15:0] count;

counter U1(clk, reset_n, enable, up_down, count);

// Handle the Clock
	always
		#5 clk <= ~clk;

initial
	begin
			reset_n <= 0;
			enable  <= 0;
			clk	  <= 0;
			up_down <= 1;

			#10 reset_n <= 1;
	end

endmodule
