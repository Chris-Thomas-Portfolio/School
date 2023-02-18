module systemD (Clk, D, Qa, Qb, Qc);
	input Clk, D;
	output reg Qa, Qb, Qc;
	
	//gated D-latch
	//Use an always block for a gated D input
	
	//your code here
	always @(D, Clk)
		if(Clk)
			Qa <= D;

	//positive-edge triggered D-FF
	//Use an always block for a positive-edge triggered D-FF
	
	//your code goes here

	always @(posedge Clk)
			Qb <= D;
	
	//negative-edge triggered D ff
	
	always @(negedge Clk)
			Qc <= D;
			
endmodule 