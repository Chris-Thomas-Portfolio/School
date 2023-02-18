//one-digit BCD adder S1 S0 = X + Y + Cin
//inputs: SW7-4 = x
//		SW3-0 = Y
//		SW8 = Cin
//outputs: X is displayed on HEX5
//								Y is displayed on HEX3
//								S1 S0 is displayed on HEX1 HEX0

module bcd_4bitadder(SW,LEDR,HEX5,HEX4,HEX3,HEX2,HEX1,HEX0);
		input [8:0] SW;
		output [9:0] LEDR;
		
		output [0:6] HEX5,HEX4,HEX3,HEX2,HEX1,HEX0;
		
		wire Cin;
		wire [3:0] X;
		wire [3:0] Y;
		wire [3:0] S;
		wire [4:1] C;
		wire [3:0] M;
		wire [3:0] B;
		wire [3:0] S0;
		wire z, S1;
		
		assign X = SW[7:4];
		assign Y = SW[3:0];
		assign Cin = SW[8];
		
		fa bit0 (X[0], Y[0], Cin, S[0], C[1]);			//send the first adder the appropriate inputs
		fa bit1 (X[1], Y[1], C[1], S[1], C[2]);		//carry the first carry to the second adder and send it the appropriate inputs
		fa bit2 (X[2], Y[2], C[2], S[2], C[3]);		//carry the second carry to the second adder and send it the appropriate inputs
		fa bit3 (X[3], Y[3], C[3], S[3], C[4]);		//carry the third carry to the second adder and send it the appropriate inputs
		
		assign LEDR[4] = C[4];								//assign LEDR[4] to the output of the final carry.
		assign LEDR[3:0] = S[3:0];
		
		bcd7seg U1(X, HEX5);									//send X to HEX5 
		bcd7seg U2(Y, HEX3);									//send Y to HEX3
		assign HEX4 = 1;										//set HEX4 and HEX2 
		assign HEX2 = 1;
		
		assign LEDR[9] = (X > 4'b1001 | Y > 4'b1001); //Light up LEDR[9] when X or Y are greater than 9
		assign LEDR[8:5] = 4'b0000;						//set unused LEDRs to off
		
		bcd_decimal U3(S, z, M);							//Convert the sum value to decimal. 
		
		assign B = C[4] ? ({C[4],S} - 10) : M;			//assign B for values 16-19
		
		mux2to1_4bit U4(M, B, C[4], S0);					//determine if using M or B 
		
		bcd7seg U5(S0, HEX0);								//send the value to HEX0
		
		assign S1 = {C[4],S} > 10 ? 4'b0001 : 4'b0000; //assign S1 to the values necessary for when we want HEX1 to be a 1.
		
		bcd7seg U6(S1, HEX1);									//send 1 or 0 to HEX1 based on S1
		
endmodule		