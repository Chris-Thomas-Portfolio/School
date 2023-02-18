`timescale 1ns / 1ps

module clk_FSM_tb();

reg clk, reset, set, hour, minute;

wire am;
wire [5:0] seconds, minutes;
wire [3:0] hours;
wire [1:0] state;

clk_FSM			U1(clk, reset, set, hour, minute, am, seconds, minutes, hours);

initial
	begin
		clk <= 0;
		reset <= 1;
		set <= 1;
		hour <= 1;
		minute <= 1;
		
		#5 reset <= 0;
		#5 reset <= 1;
		#620 set <= 0;
		#5 minute <= 0;
		
	end

	always
		#5 clk <= ~clk;

endmodule
