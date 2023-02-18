`timescale 1ns / 1ps

module fsm_alu_tb();

reg [2:0] opcode;
reg [3:0] a;
reg [3:0] b;
reg clk, reset, go;
wire [4:0] result;
wire cout, led_idle, led_ready, led_done;
wire [3:0] state;


fsm_alu			U1(opcode, a, b, clk, reset, go, result, cout, led_idle, led_ready, led_done);

initial
	begin
		opcode <= 0;
		a <= 0;
		b <= 0;
		clk <= 0;
		reset <= 0;
		go <= 0;
		
		#5 reset <= 1;
		#5 reset <= 0;
		
		#5 a <= 9;
		#5 b <= 9;
		#5 go <= 1;
		#5 go <= 0;
		#5 opcode <= 1;
		#5 go <= 1;
		#5 go <= 0;
		#5 opcode <= 2;
		#5 go <= 1;
		#5 go <= 0;
		#5 opcode <= 3;
		#5 go <= 1;
		#5 go <= 0;
		#5 opcode <= 4;
		#5 go <= 1;
		#5 go <= 0;
		#5 opcode <= 5;
		#5 go <= 1;
		#5 go <= 0;
		#5 opcode <= 6;
		#5 go <= 1;
		#5 go <= 0;
		#5 opcode <= 7;
		#5 go <= 1;
		#5 go <= 0;
	
		
	end

	always
		#5 clk <= ~clk;

endmodule
