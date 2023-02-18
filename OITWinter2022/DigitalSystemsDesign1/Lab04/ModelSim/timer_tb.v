`timescale 1ns / 1ps

module timer_tb();

reg clk, enable;



wire time_up;

timer		U1(clk, enable, time_up);

always
	#1 clk <= ~clk;

initial
	begin
		clk <= 0;
		enable <= 0;
		#5 enable <= 1;
	end

endmodule
