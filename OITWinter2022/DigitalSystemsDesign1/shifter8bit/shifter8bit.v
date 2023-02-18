module shifter8bit(
	input [7:0] data_in,
	input [2:0] sh_amt,
	input [1:0] opcode,
	output [7:0] data_out
);

shifter U1(data_in, sh_amt, opcode, data_out);

endmodule