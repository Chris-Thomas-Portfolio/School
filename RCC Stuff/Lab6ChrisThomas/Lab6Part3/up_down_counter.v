module up_down_counter(
	input clk, 
	input up_dn,  					// count up or down selection
	input LD,  						// load data
	input reset,  					// reset
	input [7:0] D,  				// data 
	output reg [7:0] Q
	);
	

	always @ (posedge clk)  
		begin
			if (reset)					// if reset is active set the output to 0
				begin
					Q = 8'b00000000;
				end
			else if (LD)				// if load is active set output to D
				begin
					Q = D;
				end
			else if(up_dn)				// if up/down is active count down
				begin
					Q = Q - 1;
				end
			else 
				begin
					Q = Q + 1;			// if up/down is low count up
				end
		end
		
	
endmodule  // up_down_counter