`timescale 1ns / 1ps

module key_sequence_tb();

reg clk;
reg key_pressed;
reg time_up;
reg [3:0] key;
wire reset;
wire [15:0] sequence;
wire kp;
wire [2:0] state; 
wire [15:0] temp;

key_sequence_gen			U1(clk, key_pressed, time_up, key, reset, sequence, kp, temp);

initial
	begin
		clk <= 0;
		key_pressed <= 0;
		time_up <= 0;
		key <= 0;
		
		#20 key <= 1;
		#20 key <= 2;
		#20 key <= 3;
		#20 key <= 4;
		#40 key <= 5;
		#20 key <= 6;
		#20 key <= 7;
		#20 key <= 8;
		
		#20 key <= 4'b1111;
	end
		
	always
		#5 clk <= ~clk;
		
	always
		#10 key_pressed <= ~key_pressed;
		
endmodule