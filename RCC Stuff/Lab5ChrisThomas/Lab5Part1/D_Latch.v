//A gated D latch described the hard way
module D_Latch(Clk, D, Q);

	input Clk, D;
	output Q;
	
	wire R, S_g, R_g, Qa, Qb/*synthesis keep*/;
	
//Use assignment operators to implement Figure 1;
	//your code goes here
	assign S_g = ~(D & Clk);			//NAND D and Clk together
	assign R_g = ~(~D & Clk);			//NAND ~D and CLK together
	assign Qa = ~(S_g & Qb);			//NAND S_g and Qb together
	assign Qb = ~(R_g & Qa);			//NAND R_g and Qa together
	assign Q = Qa;							//assign the output to Qa
	
endmodule