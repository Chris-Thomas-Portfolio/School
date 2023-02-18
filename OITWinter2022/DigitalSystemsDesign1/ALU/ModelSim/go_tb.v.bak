`timescale 1ns / 1ps

module key_scanner_tb ();

reg clk_2kHz; 
reg [3:0] columns;
wire [3:0] rows;
wire [3:0] key;
wire [1:0] count;
wire	key_pressed;

key_scanner U1(clk_2kHz, columns, rows, key);

// Handle the Clock
	always
		#5 clk_2kHz <= ~clk_2kHz;

initial
	begin		
			clk_2kHz <= 0;
			columns[3:0] <= 4'b1111;
			#10 columns[3:0] <= 4'b0111;
			#10 columns[3:0] <= 4'b1111;
			#40 columns[3:0] <= 4'b1011; 
			#10 columns[3:0] <= 4'b1111;
			#40 columns[3:0] <= 4'b1101; 
			#10 columns[3:0] <= 4'b1111;
			#40 columns[3:0] <= 4'b1110; 
	end
	
endmodule