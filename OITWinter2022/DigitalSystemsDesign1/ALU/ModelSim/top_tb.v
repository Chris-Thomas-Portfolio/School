`timescale 1ns / 1ps

module top_tb();

reg clk;
reg reset;
reg go;
reg [2:0] opcode;
reg [3:0] data;
wire wait_led, cout, led_idle, led_ready, led_done;
wire [4:0] result;


ALU	U1(clk, reset, go, opcode, a, b, wait_led, cout, led_idle, led_ready, led_done);

initial
	begin
		clk <= 0;
		reset <= 0;
		go <= 0;
		opcode <= 0;
		b <= 0;
		a <= 4;
		
		#5 reset <= 1;
		#5 reset <= 0;
		
		#10 go <= 1;
		#10 go <= 0;
		
		#10 opcode <= 1;
		#10 go <= 1;
		#10 go <= 0;
		
		#10 opcode <= 2;
		#10 go <= 1;
		#10 go <= 0;
		
		#10 opcode <= 3;
		#10 go <= 1;
		#10 go <= 0;
		
		#10 opcode <= 4;
		#10 go <= 1;
		#10 go <= 0;
		
		#10 opcode <= 5;
		#10 go <= 1;
		#10 go <= 0;
		
		#10 opcode <= 6;
		#10 go <= 1;
		#10 go <= 0;
		
		#10 opcode <= 7;
		#10 go <= 1;
		#10 go <= 0;
	end

	always
		#5 clk <= ~clk;

endmodule
