//Display digits from 0 to 9 on the 7-segment displays, using the SW
//toggle switches as inputs.

module display7seg(SW,LEDR,HEX1,HEX0);
	input [7:0] SW;							//8 input switches
	output [7:0] LEDR;						//8 LED outputs
	output [0:6] HEX1,HEX0;					//2 x 7-segment displays
	
	assign LEDR = SW;							//condition of switches indicated by LEDs
	
//drive the displays through 7-segment decoders
	
	bcd7seg digit1(SW[7:4],HEX1);			//reference to sub-module bcd7seg
	bcd7seg digit0(SW[3:0],HEX0);			//reference to sub-module bcd7seg
	
endmodule //end display7seg