//   Author: Chris Thomas
//   Lab: Lab03
//   Project: Multiplexed Display
//   File Name: bcd_to_decimal.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Takes the bcd value and turns on the proper segments of the seven segment display.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module bcd_to_decimal(
    input [3:0] hex,
    output reg [6:0] display
);

always @(hex)
    case(hex)
        4'h0: display = ~(7'b1000000);
        4'h1: display = ~(7'b1111001);
        4'h2: display = ~(7'b0100100);		
        4'h3: display = ~(7'b0110000);	
        4'h4: display = ~(7'b0011001);	
        4'h5: display = ~(7'b0010010);	
        4'h6: display = ~(7'b0000010);	
        4'h7: display = ~(7'b1111000);	
        4'h8: display = ~(7'b0000000);	
        4'h9: display = ~(7'b0011000);	
        default : display = ~(7'b1111111);
    endcase


endmodule