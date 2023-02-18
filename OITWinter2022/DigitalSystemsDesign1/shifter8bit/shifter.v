//   Author: Chris Thomas
//   Lab: HW 1 Question 1
//   Project: shifter8bit
//   File Name: shifter.v
//-----------------------------------------------------------------------------
//   Description of the Code:
//   This module handles modifies the value of input "original" by the amount
//		specified by the input "amount". It either shifts left or right or rotates 
//		left or right depending on the value of input "opcode".
//-----------------------------------------------------------------------------
//   Date: 02/02/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------

module shifter(
input [7:0] original,
input [2:0] amount,
input [1:0] opcode,
output reg [7:0] result
);

always @(original or amount or opcode)
	begin
		case(opcode)
			2'b00 :					//opcode for rotate left
				begin
					result <= (original >> amount) | (original << (8-amount));	//rotate value left
				end
			2'b01 :					//opcode for shift left
				begin
					result <= original << amount;		//shift value left
				end
			2'b10 :					//opcode for rotate right
				begin
					result <= (original << amount) | (original >> (8-amount));	//rotate value right
				end
			2'b11 :					//opcode for shift right
				begin
					result <= original >> amount;		//shift value right
				end	
		endcase
	end
endmodule