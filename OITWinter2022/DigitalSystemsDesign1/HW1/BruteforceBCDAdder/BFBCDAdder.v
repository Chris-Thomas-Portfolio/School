module BFBCDAdder(
input [7:0] SW,
output [4:0] LEDR
);

add_bcd	U1(SW[3:0], SW[7:4], LEDR[0], LEDR[4:1]);

endmodule