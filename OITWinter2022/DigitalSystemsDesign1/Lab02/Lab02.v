module Lab02(
input CLOCK_50,
input  [1:0] SW,
output [6:0] HEX0,
output [6:0] HEX1,
output [6:0] HEX2,
output [6:0] HEX3,
output [6:0] HEX4
);


wire q;
wire [15:0] p;
wire [19:0]	g;

clk_divider			divider(CLOCK_50, q);
counter				count(q, SW[1], SW[0], p);
bcd					U1(p, g);
bcd_decimal			M1(g[3:0], 	 HEX0);
bcd_decimal			M2(g[7:4], 	 HEX1);
bcd_decimal			M3(g[11:8],  HEX2);
bcd_decimal			M4(g[15:12], HEX3);
bcd_decimal			M5(g[19:16], HEX4);

endmodule