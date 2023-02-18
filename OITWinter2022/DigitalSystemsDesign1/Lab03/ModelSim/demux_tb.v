`timescale 1ns / 1ps

module demux_tb ();

reg clk;
reg [1:0] sel;
wire [3:0] dis_sel;


demux U1(clk, sel, dis_sel);

// Handle the Clock
	always
		#5 clk <= ~clk;
		
	always 
		#10 sel <= sel + 1;
		
initial
	begin
			clk <= 0;
			sel <= 0;
	end
	
endmodule