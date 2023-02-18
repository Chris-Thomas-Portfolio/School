module MUX4to1(
input wire [3:0] c,			//4-inputs c0,c1,c2, and c3
input wire [1:0] s,			//2-selector inputs s0 and s1
output wire z,					//1-output z for final MUX
output [9:1] LEDR
);

assign LEDR [9:1] = 8'b00000000;
wire v;
wire w;

MUX2to1a M1 (.x(c[0]),					//connect x to c[o]
					.y(c[1]),				//connect y to c[1]
					.z(s[0]),				//connect z to [s0]
					.m(v)						//connect m to v
					
);

MUX2to1a M2 (.x(c[2]),					//connect x to c[2]
					.y(c[3]),				//connect y to c[3]
					.z(s[0]),				//connect z to s[0]
					.m(w)						//connect m to w

);

MUX2to1a M3 (.x(v),						//connect x to v
					.y(w),					//connect y to w
					.z(s[1]),				//connect z to s[1]
					.m(z)						//connect m to z

);

endmodule