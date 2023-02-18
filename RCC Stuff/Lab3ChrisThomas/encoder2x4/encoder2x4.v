module encoder2x4(enable,a,r,valid,LEDR);
input enable;
input [3:0] a;
output [1:0] r;
output valid;
output [9:3] LEDR;

assign LEDR [9:3] = 7'b0000000;													//assign unused LEDs to low

assign valid = (~a[0] & ~a[1] & ~a[2] & ~a[3] & ~enable)					//turn valid high if enable is high or all inputs are low
					|(enable);


assign r[1] = (a[2] & ~enable)													//turn r[1] high if a[2] or a[3] are high while enable is low
					|(a[3] & ~enable);
					
assign r[0] = (a[1] & ~enable)													//turn r[0] high if a[1] or a[3] are high while enable is low
					|(a[3] & ~enable);
					

endmodule		 