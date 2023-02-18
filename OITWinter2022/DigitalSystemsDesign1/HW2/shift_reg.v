//   Author: Chris Thomas
//   Lab: HW2
//   Project: Bit serial adder
//   File Name: shift_reg.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Shift register for serial adder.
//-----------------------------------------------------------------------------
//   Date: 03/01/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module shift_reg(
	input [3:0] data,
	input clk,
	input load,
	input shr,
	input clr,
	output reg a
);


reg [3:0] temp;
reg [2:0] shift;

/*Init block for testbench*/
initial
	begin
		a <= 0;
		temp  <= 0;
		shift <= 0;
	end
	
	always @(posedge clk)
		begin
			if(load)								//load in data
				begin
					temp <= data;
				end
			else if(shr)						//shift temp and load into a
				begin
					a <= temp >> shift;
					shift <= shift + 1;
				end
			else if(clr)						//clear temp and a
				begin
					temp <= 0;
					a <= 0;
				end
			else
				begin
					temp <= temp;
				end		
		end
endmodule
			
