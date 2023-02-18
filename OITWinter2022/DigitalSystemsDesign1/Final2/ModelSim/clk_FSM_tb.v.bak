`timescale 1ns / 1ps

module transmit_control_tb();

reg clk, transmit;

wire but;
wire [1:0] state;

transmit_control			UUT1(clk, transmit, but);

initial
	begin
		clk <= 0;
		transmit <= 1;
		
		#10 transmit <= 0;
		#50 transmit <= 1;
	end

	always
		#5 clk <= ~clk;

endmodule
