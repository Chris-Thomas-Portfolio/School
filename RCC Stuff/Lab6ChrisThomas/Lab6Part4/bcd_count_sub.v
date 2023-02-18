module bcd_count_sub(
	input wire clk, reset, cen, up_dn, LD,
	input [3:0] D,
	output reg [3:0] data);
	
	always @(posedge clk)
		begin
			if(reset)
				data = 4'b0000;
			else if (LD)
				data = D;
			else if(cen)
				data = data;
			else if(~up_dn)
				if(data < 4'b1001)
					data = data + 1;
				else 
					data = 4'b0000;
			else
				if(data != 4'b0000)
					data = data - 1;
				else
					data = 4'b1001;
		end
		
endmodule