module counter
	#(parameter BIT_COUNT = 16)(
	input clk,
	input reset_n,
	input enable,
	output reg[BIT_COUNT-1:0] count
);

always @(posedge clk)
	begin
		if(reset_n == 0)
			count <= 0;
		else if(enable == 0)
			count <= count + 1;
		else
			count <= count;
	end
	
endmodule