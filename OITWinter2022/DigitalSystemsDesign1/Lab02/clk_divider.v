module clk_divider(
	input clk,
	//input reset,
	output reg clk_out
);

	reg [24:0] count;	// Make the counter big enough to hold our number

	// Always block to handle the counter
	always @(posedge clk)
	begin
		//if(reset)
			//count <= 25'b0;
		if(count < 250000 - 1)	// 50 MHz / (2 x 250 kHz) = 100 Hz
			count <= count + 1;
		else
			count <= 25'b0;
	end

	// Always block to handle the flip flop portion
	always @(posedge clk)
	begin
		//if(reset)
			//clk_out <= 1'b0;
		if(count == 250000 - 1)
			clk_out <= ~clk_out;
		else
			clk_out <= clk_out;
	end
endmodule
