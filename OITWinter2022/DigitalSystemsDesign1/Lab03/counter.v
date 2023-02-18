//   Author: Chris Thomas
//   Lab: Lab03
//   Project: Multiplexed Display
//   File Name: counter.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Counts up when enable is and up_down are low and down when up_down is high and
//		enable is low.
//-----------------------------------------------------------------------------
//   Date: 02/17/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module counter
	#(parameter BIT_COUNT = 16)(
	input clk,
	input reset_n,
	input enable,
	input up_down,
	output reg[BIT_COUNT-1:0] count
);

always @(posedge clk)								
	begin
		if(reset_n == 0)								//reset count if reset is low
			count <= 0;
		else if(enable == 0 && up_down == 0)	//count up when enable is low and up_down is low
			count <= count + 1;
		else if(enable == 0 && up_down == 1)	//count down when enable is low and up_down is high
			count <= count - 1;
		else
			count <= count;							//when enable is high pause the count
	end
	
endmodule