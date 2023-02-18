//bcd-to-decimal converter
module bcd_decimal (V,z,M);
	input [3:0] V;
	output [3:0] M;
	output z;
	
	wire[3:0] A;		//intermediate wire connection for output A of Circuit A
	
	
	
	//comparator circuit for V > 9
	
	assign z = V > 4'b1001;
	
	//Circuit A: when V > 9, this circuit allows the digit d0 to display the
	//values 0-5(for the numbers V = 10 to V = 15). Note that V3 = 1 for all of these 
	//values, and V3 isn't needed in circuit A. The circuit implements the truth table
	//
	//V2 V1 V0 | A2 A1 A0
	//---------------------
	//0  1  0  | 0  0  0 (V = 1010 -> 0)
	//0  1  1  | 0  0  1 (V = 1011 -> 1)
	//1  0  0  | 0  1  0 (V = 1100 -> 2)
	//1  0  1  | 0  1  1 (V = 1101 -> 3)
	//1  1  0  | 1  0  0 (V = 1110 -> 4)
	//1  1  1  | 1  0  1 (V = 1111 -> 5)
	
	assign A[3] = 1'b0;
	assign A[2] = (V[2] & V[1] & ~V[0]) | (V[2] & V[1] & V[0]);										//A[2] to be high when V = 1110 or V = 1111
	assign A[1] = (V[2] & ~V[1] & V[0]) | (V[2] & ~V[1] & ~V[0]);									//A[1] to be high when V = 1101 or V = 1100
	assign A[0] = (~V[2] & V[1] & V[0]) | (V[2] & ~V[1] & V[0]) | (V[2] & V[1] & V[0]);		//A[0] to be high when V = 1011 or V = 1101 or V = 1111
	
	
	//U1,U2, and U3 are three submodules to be developed or reused from previous
	//experiences
	//multiplexers
	mux2to1_4bit U1 (V, A, z, M);
	
	
endmodule //end bcd_decimal