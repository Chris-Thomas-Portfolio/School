module fulladder(SW, LEDR);
	input [8:0] SW;
	output [9:0] LEDR;
	
	wire [3:0] C;
	wire [3:0] A;
	wire [3:0] B;
	wire Cin;
	wire [3:0] S;
	
	assign A[3:0] = SW[7:4];
	assign B[3:0] = SW[3:0];
	assign Cin = SW[8];
	
	fa U1(A[0], B[0], Cin, S[0], C[0]);
	fa U2(A[1], B[1], C[0], S[1], C[1]);
	fa U3(A[2], B[2], C[1], S[2], C[2]);
	fa U4(A[3], B[3], C[2], S[3], C[3]);
	
	assign LEDR [4] = C[3];
	assign LEDR [3:0] = S[3:0];
	
	assign LEDR[9:5] = 5'b0;
	
endmodule