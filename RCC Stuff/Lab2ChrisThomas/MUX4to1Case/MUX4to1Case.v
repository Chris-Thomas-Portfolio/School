module MUX4to1Case(
	output reg z,								//set z to output register
	input [0:3] c,								//set 4 inputs as c
	input [1:0] sel,							//set 2 inputs as sel
	output [9:1] LEDR							//set LEDR to output for unused LEDs
);

assign LEDR [9:1] = 8'b00000000;			//set unused to low
						
always @(*)
	
	case(sel)							
			0:z = c[0];							//if sel[0] set z = c[0]
			1:z = c[1];							//if sel[1] set z = c[1]
			2:z = c[2];							//if sel[2] set z = c[2]
			3:z = c[3];							//if sel[3] set z = c[3]
			default: z = c[0];				//default case is to set z to c[0]
	endcase
endmodule