`timescale 1ns / 1ps

module taillight_FSM_tb();

reg clk, left, right, bk, haz;

wire [5:0] led;
wire [1:0] state;


taillight_FSM			U1(clk, left, right, bk, haz, led);

initial
	begin
		clk <= 0;
		left <= 0;
		right <= 0;
		bk <= 0;
		haz <= 0;
		
		#5 left <= 1;
		#15 left <= 0;
		#5 right <= 1;
		#15 right <= 0;
		#5 bk <= 1;
		#15 bk <= 0;
		#5 haz <= 1;
		#25 haz <= 0;
		#5 left <= 1;
		#5 bk <= 1;
		#15 left <= 0;
		#5 right <= 1;
		#15 left <= 1;
		#15 bk <= 0;
		

	end

	always
	#5 clk <= ~clk;

endmodule
