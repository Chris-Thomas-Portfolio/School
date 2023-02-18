module addsub(
	input [3:0] a,
	input [3:0] b,
	input add_sub,	  // if this is 1, add; else subtract
	input clk,
	output reg [3:0] result
);

	always @ (posedge clk)
	begin
		if (add_sub)
			result <= a + b;
		else
			result <= a - b;
	end

endmodule
