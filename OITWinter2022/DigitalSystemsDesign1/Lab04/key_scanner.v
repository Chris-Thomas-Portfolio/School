//   Author: Chris Thomas
//   Lab: Lab04
//   Project: Keypad
//   File Name: key_scanner.v
//   List of other files used: N/A 
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Uses a counter to rotate through the rows case statements and reads values
//	  from columns to determine which key is pressed and outputs that value.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module key_scanner(
	input clk_20Hz,
	input [3:0] columns,
	output reg [3:0] rows,
	output reg [3:0] key,
	output reg key_pressed
);

reg [1:0] count;

//init block for testbench
initial
	begin
		rows <= 4'b1111;
		key <= 4'bzzzz;
		count <= 0;
		key_pressed <= 0;
	end

always @(posedge clk_20Hz)						//increase count on each posedge of clock
	begin
		count <= count + 1;
	end
	
always @(posedge clk_20Hz)									//when count changes enter case statement
	begin
		case (count)
				2'b00:
				begin
					case (columns)					//check to see if columns is any of these values
							4'b0111:
								begin
									key_pressed <= 1;
									key <= 4'b0001;
								end
							4'b1011:
								begin
									key_pressed <= 1;
									key <= 4'b0010;
								end
							4'b1101:
								begin
									key_pressed <= 1;
									key <= 4'b0011;	//if so set key to specified value
								end
							4'b1110:
								begin
									key_pressed <= 1;
									key <= 4'b1010;
								end
							default:
								begin
									key_pressed <= 0;
									key <= 4'b0000;
								end
					endcase
					rows <= 4'b1011;
				end
				2'b01:
				begin
					case (columns)
							4'b0111:
								begin
									key_pressed <= 1;
									key <= 4'b0100;
								end
							4'b1011:
								begin
									key_pressed <= 1;
									key <= 4'b0101;
								end
							4'b1101:
								begin
									key_pressed <= 1;
									key <= 4'b0110;
								end
							4'b1110:
								begin
									key_pressed <= 1;
									key <= 4'b1011;
								end
							default:
								begin
									key_pressed <= 0;
									key <= 4'b0000;
								end
					endcase
					rows <= 4'b1101;
				end
				2'b10:
				begin
					case (columns)
							4'b0111:
								begin
									key_pressed <= 1;
									key <= 4'b0111;
								end
							4'b1011:
								begin
									key_pressed <= 1;
									key <= 4'b1000;
								end
							4'b1101:
								begin
									key_pressed <= 1;
									key <= 4'b1001;
								end
							4'b1110:
								begin
									key_pressed <= 1;
									key <= 4'b1100;
								end
							default:
								begin
									key_pressed <= 0;
									key <= 4'b0000;
								end
					endcase
					rows <= 4'b1110;
				end
				2'b11:
				begin
					case (columns)
							4'b0111:
								begin
									key_pressed <= 1;
									key <= 4'b1110;
								end
							4'b1011:
								begin
									key_pressed <= 1;
									key <= 4'b0000;
								end
							4'b1101:
								begin
									key_pressed <= 1;
									key <= 4'b1111;
								end
							4'b1110:
								begin
									key_pressed <= 1;
									key <= 4'b1101;
								end
							default:
								begin
									key_pressed <= 0;
									key <= 4'b0000;
								end
					endcase
					rows <= 4'b0111;
				end
				default:
					begin
						key <= 4'bzzzz;
						key_pressed <= 0;
					end
		endcase
	end
endmodule