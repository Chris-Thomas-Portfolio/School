`timescale 1ns / 1ps

module shifter_tb();

reg [7:0] original;

reg [2:0] amount;

reg [1:0] opcode;

wire [7:0] result;

shifter U1(original, amount, opcode, result);

initial
	begin
		original <= 8'b00000001;
		amount 	<= 3'b000;
		opcode	<= 2'b00;
		
		#20 amount 		<= 3'b001;
		#20 opcode		<= 2'b10;
		#20 original 	<= 8'b10001110;
		#20 opcode		<= 2'b11;
		#20 opcode 		<= 2'b01;
	end
	
endmodule