//   Author: Chris Thomas
//   Lab: Lab 1
//   Project: 4-Bit Adder
//   File Name: Lab01.v
//   List of other files used: Adder 4-Bit.v, 7Seg.v, etc.
//-----------------------------------------------------------------------------
//   Description of the Code (1 - 5 lines)
//   This module handles all the case statements for the 7-segment display.
//-----------------------------------------------------------------------------
//   Date: 01/5/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------

module bin7seg(
    input [4:0] bin,
    output reg [6:0] display1, display10
    );
//create a case statement for each possible value.
always @(bin)
    case(bin)
        5'b00000: 
						begin									//0
							display1  = 7'b0000001; 
							display10 = 7'b0000001;
						end
						
        5'b00001: 
						begin									//1
							display1  = 7'b1001111; 
							display10 = 7'b0000001;
						end
						
        5'b00010: 
						begin									//2
							display1  = 7'b0010010; 
							display10 = 7'b0000001;
						end
						
        5'b00011: 
						begin									//3
							display1  = 7'b0000110; 
							display10 = 7'b0000001;
						end
						
        5'b00100: begin									//4
							display1 = 7'b1001100; 
							display10 = 7'b0000001;
						end
						
        5'b00101: 
						begin									//5
							display1  = 7'b0100100; 
							display10 = 7'b0000001;
						end
						
        5'b00110: 
						begin									//6
							display1  = 7'b0100000; 
							display10 = 7'b0000001;
						end
						
        5'b00111: 
						begin									//7
							display1  = 7'b0001111; 
							display10 = 7'b0000001;
						end
						
        5'b01000: 
						begin									//8
							display1  = 7'b0000000; 
							display10 = 7'b0000001;
						end
						
        5'b01001: 
						begin									//9
							display1  = 7'b0001100; 
							display10 = 7'b0000001;
						end
						
        5'b01010: 
						begin									//10
							display1  = 7'b0000001; 
							display10 = 7'b1001111;
						end
						
        5'b01011: 
						begin									//11
							display1  = 7'b1001111; 
							display10 = 7'b1001111;
						end
						
        5'b01100: 
						begin									//12
							display1  = 7'b0010010; 
							display10 = 7'b1001111;
						end
						
        5'b01101: 
						begin									//13
							display1  = 7'b0000110; 
							display10 = 7'b1001111;
						end
						
        5'b01110: 
						begin									//14
							display1  = 7'b1001100; 
							display10 = 7'b1001111;
						end
						
        5'b01111: 
						begin									//15
							display1  = 7'b0100100; 
							display10 = 7'b1001111;
						end
						
		  5'b10000: 
						begin									//16
							display1  = 7'b0100000;
							display10 = 7'b1001111;
						end
						
		  5'b10001: 
						begin									//17
							display1  = 7'b0001111; 
							display10 = 7'b1001111;
						end
						
        5'b10010: 
						begin									//18
							display1  = 7'b0000000; 
							display10 = 7'b1001111;
						end
						
        5'b10011: 
						begin									//19
							display1  = 7'b0001100;  
							display10 = 7'b1001111;
						end
						
		  5'b10100: 
						begin									//20
							display1  = 7'b0000001; 
							display10 = 7'b0010010;
						end
						
        5'b10101: 
						begin									//21
							display1  = 7'b1001111; 
							display10 = 7'b0010010;
						end
						
        5'b10110: 
						begin									//22
							display1  = 7'b0010010; 
							display10 = 7'b0010010;
						end
						
        5'b10111: 
						begin									//23
							display1  = 7'b0000110; 
							display10 = 7'b0010010;
						end
						
        5'b11000: 
						begin									//24
							display1  = 7'b1001100; 
							display10 = 7'b0010010;
						end
						
        5'b11001: 
						begin									//25
							display1  = 7'b0100100; 
							display10 = 7'b0010010;
						end
						
		  5'b11010: 
						begin									//26
							display1  = 7'b0100000; 
							display10 = 7'b0010010;
						end
						
		  5'b11011: 
						begin									//27
							display1  = 7'b0001111; 
							display10 = 7'b0010010;
						end
						
        5'b11100: 
						begin									//28
							display1  = 7'b0000000; 
							display10 = 7'b0010010;
						end
						
        5'b11101: 
						begin									//29					
							display1  = 7'b0001100; 
							display10 = 7'b0010010;
						end
						
		  5'b11110: 
						begin									//30
							display1  = 7'b0000001;
							display10 = 7'b0000110; 
						end
						
        default : 
						begin
							display1  = 7'b0000001; 
							display10 = 7'b0000001;
						end
    endcase
endmodule