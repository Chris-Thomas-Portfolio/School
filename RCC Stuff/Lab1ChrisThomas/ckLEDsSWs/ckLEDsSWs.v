module ckLEDsSWs (SW,LEDR);

	input [9:0] SW;					//toggle switches
	output [9:0] LEDR;				// red LEDs
	
	assign LEDR[9:0] = SW[9:0]; 	// assign individual switches to associated LEDs
	
endmodule