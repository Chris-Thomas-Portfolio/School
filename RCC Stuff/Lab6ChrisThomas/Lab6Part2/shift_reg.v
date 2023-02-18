module shift_reg(
	input L_R,  
	input LD,   
	input [3:0] D, 
	input sin,  
	input clk, 
	input reset, 
	output [3:0] Q,  
	output sout
	);
	
	reg [3:0] temp;							// temporary register for output
	reg [2:0] count = 0;						// variable for shift
	
	always @(posedge clk)
	begin
		if(LD)									// increase shift variable
			begin
				if (count < 4)
					count <= count + 1;
				else
					count <= 0;
			end
		else
			count <= 0;
		end
					
	always @(posedge clk)
	begin
		if(LD && !sin)							
			begin
				if(L_R)							//check for shifting left or right
					temp <= D << count;
				else
					temp <= D >> count;
			end
		else if(!LD && sin)
			begin
				if(L_R)							//check for shifting left or right
					temp <= sin << count;
				else
					temp <= sin >> count;
			end
		else
			temp <= 4'b0000;
	end
	
	assign sout = L_R ? Q[0] : Q[3];
	assign Q = temp;							// send temp to the output
			
	
endmodule 
	