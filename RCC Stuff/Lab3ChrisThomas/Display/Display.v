//Implements a decoder circuit that can display characters on a 7-segment display.
//Inputs:	C = SW 1-0 selects the character to display:
//		SW 1 0 Char
//		----------- For these inputs on C for 2-inputs; What does the results display?
//		 0 0    'U'
//		 0 1    '7' with top right corner missing
//		 1 0    '2' with top left corner missing
//     1 1    '3'
//outputs LEDR1-0 show the states of the switches
//			 HEX0 displays the selected character
module Display(SW,LEDR,HEX0,);
		input [1:0] SW;				//toggle switches	//Determine which switches?
		output [9:0] LEDR;				//red LEDs
		output [0:6] HEX0;				// 7-seg display
		
		wire [1:0] C;			//internal wire between switches and the decoder ckt						
		
		assign LEDR[1:0] = SW;	//Determine which switches?
		assign LEDR[9:2] = 8'b0;	//This shuts off the LEDRs we are not using.
		
		assign C = SW;
//The following equations describe HEX0[]0-6 in SOP form
//There will be duplicate assignment statements for the two inputs
		assign HEX0[0] = ~C[0];
		assign HEX0[1] = ~C[1] & C[0];
		assign HEX0[2] = C[1] & ~C[0];
		assign HEX0[3] = ~C[1] & C[0];
		assign HEX0[4] = C[0];
		assign HEX0[5] = ~(~C[1] & ~C[0]);
		assign HEX0[6] = ~C[1];
		
endmodule