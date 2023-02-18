//inputs:
//		Clk: manual clock
//		D: data input
//
//outputs:
//		Qa:gated D-latch output
//		Qb:positive edge-triggered D flip-flop output
//		Qc:negative edge-Triggered D flip-flop output
module Lab5Part3(SW, LEDR);
	input [1:0] SW;
	output [9:0] LEDR;
	
	systemD FF(.Clk(SW[1]),				//assign Clk to SW[1]
					.D(SW[0]),				//assign D to SW[0]
					.Qa(LEDR[0]),			//assign Qa to LEDR[0]
					.Qb(LEDR[1]),			//assign Qb to LEDR[1]
					.Qc(LEDR[2])			//assign Qc to LEDR[2]
	);
	
endmodule