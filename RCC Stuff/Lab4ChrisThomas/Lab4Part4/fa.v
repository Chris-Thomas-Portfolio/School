module fa (a, b, ci, s, co);
	input a, b, ci;
	output s, co;
	
	wire a_xor_b;
	
	assign s = (~a & ~b & ci) | (a & ~b & ~ci) | (~a & b & ~ci) | (a & b & ci);	//assign sum when the 3 inputs are the appropriate values
	assign co = (a & ~b & ci) | (~a & b & ci) | (a & b & ~ci) | (a & b & ci);		//assign co when the 3 inputs are the appropriate values
	
endmodule