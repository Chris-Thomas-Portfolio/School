`timescale 1ns / 1ps

module go_tb ();

reg clk, reset, go;
reg [3:0] data_in;

wire [2:0] state;
wire [3:0] data;
wire wait_led, state_change;

go U1(clk, reset, go, data_in, data, wait_led, state_change);

// Handle the Clock
	always
		#5 clk <= ~clk;

initial
	begin		
		clk <= 0;
		reset <= 0;
		go <= 0;
		data_in <= 4'b1010;
		
		#10 reset <= 1;
		#10 reset <= 0;
		#10 go <= 1;
		#10 go <= 0;
		#10 data_in <= 4'b0101;
		#10 go <= 1;
		#10 data_in <= 4'b1111;
		#10 go <= 0;
		
	end
	
endmodule