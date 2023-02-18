module Adder(
	input A,B,Cin,				//input declarations
	output Sum,Cout);			//output declarations
	
	wire S1,T1,T2,T3;			//intermediate or internal connections between the gates
	
//structural code for the full adder

xor U1(S1,A,B); 				// 2 input xor gate with S1 output
xor U2(Sum,S1,Cin);			// 2 input xor gate with Sum output

and U3(T3,A,B);				// 2 input and gate with T3 output
and U4(T2,B,Cin);				// 2 input and gate with T2 output
and U5(T1,A,Cin);				// 2 input and gate with T1 output

or U6(Cout,T1,T2,T3);		// 3 input or gate with Cout output

endmodule