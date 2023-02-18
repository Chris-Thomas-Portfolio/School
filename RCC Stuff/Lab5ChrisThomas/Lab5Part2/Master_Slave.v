//Create a Master and slave D_Latch circuit
module Master_Slave(SW, LEDR);
	input [1:0] SW;
	output [9:0] LEDR;
	
	wire Qm;
	//Create master giving it the D input and the inverted Clk input
	D_Latch master(.D(SW[0]),
						.Clk(~SW[1]),
						.Q(Qm)
	);
	//Create the slave giving it the Q from the master and the Clk input and sending that output to LEDR[0]
	D_Latch slave(.D(Qm),
						.Clk(SW[1]),
						.Q(LEDR[0])
	);
	
endmodule