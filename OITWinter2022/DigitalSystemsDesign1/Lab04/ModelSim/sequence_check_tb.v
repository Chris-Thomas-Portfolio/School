`timescale 1ns / 1ps

module sequence_check_tb();

reg clk;
reg times_up;
reg [15:0] sequence;
reg new_seq;
wire unlock;
wire error;
wire start_time;

sequence_check			U1(clk, times_up, sequence, new_seq, unlock, error, start_time);

initial
	begin
		clk <= 0;
		times_up <= 0;
		sequence <= 4'h0000;
		new_seq <= 1;

		#20 sequence <= 16'h1234;
		#20 sequence <= 16'hABCD;
		#20 sequence <= 16'h1122;
		#20 sequence <= 16'h1010;
		#20 sequence <= 16'h123A;
		#20 sequence <= 16'h2580;
		#20 sequence <= 16'h1111;

	end

	always
		#5 clk <= ~clk;
	always
		#20 times_up <= ~times_up;

endmodule
