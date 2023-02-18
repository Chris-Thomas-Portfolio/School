module ElegantBCDAdder(
input [3:0] a,
input [3:0] b,
output reg cout,
output reg [3:0] s
);

reg [4:0] s_temp;						//temp register

always @(*)
	begin
		s_temp = a+b; 					//add inputs into temp register
      if(s_temp > 9)    
			begin
				s_temp = s_temp+6; 	//if addition is more than 9 add 6 to value.
				cout = 1;  				//set the carry output
				s = s_temp[3:0];    	//set s to what is in temp
			end
      else    
			begin
				cout = 0;
				s = s_temp[3:0];
			end
	end
endmodule