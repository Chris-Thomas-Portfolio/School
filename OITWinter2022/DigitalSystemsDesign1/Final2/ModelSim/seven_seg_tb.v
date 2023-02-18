`timescale 1ns / 1ps

module seven_seg_tb();

reg [3:0] hex;

wire [6:0] display;

seven_seg			U1(hex, display);

initial
	begin
		hex <= 4'b000;
	end

	always
		#5 hex <= hex + 1;

endmodule
