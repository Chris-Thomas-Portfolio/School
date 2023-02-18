//Top Level for Clocked D Latch Circuitd

module Clkd_Latch(SW, LEDR);
	input [1:0] SW;
	output [9:0] LEDR;
	
	//assign the switches to the the appropriate inputs for D_Latch
	D_Latch U1 (.D(SW[0]),
					.Clk(SW[1]),
					.Q(LEDR[0])
	
	);
	
endmodule