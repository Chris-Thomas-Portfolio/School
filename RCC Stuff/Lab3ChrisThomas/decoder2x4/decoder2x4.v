module decoder2x4(enable, p, a, y, LEDR);
	input enable;
	input p;
	input [1:0] a;
	output reg[0:3] y;
	output[9:4] LEDR;

	assign LEDR [9:4] = 6'b000000;	//set unused LEDs to low

	always @(*)
		if(enable == 1)					//if enable is high set the outputs to high impedance
			y = 1'bz;
		else
			if(~p)							//check to see if p is 0
				if(~a[1] & ~a[0])			//if a[1] and a[0] are both 0 set y to 1000
					y = 4'b1000;
				else if(~a[1] & a[0])	//if a[1] is 0 and a[0] is 1 set y to 0100
					y = 4'b0100;
				else if(a[1] & ~a[0])	//if a[1] is 1 and a[0] is 0 set y to 0010
					y = 4'b0010;
				else
					y = 4'b0001;			//if both a[1] and a[0] are 1 set y to 0001
			else								//if p is not 0 do this if statement
				if(~a[1] & ~a[0])			//if a[1] and a[0] are both 0 set y to 0111
					y = 4'b0111;
				else if(~a[1] & a[0])	//if a[1] is 0 and a[0] is 1 set y to 1011
					y = 4'b1011;
				else if(a[1] & ~a[0])	//if a[1] is 1 and a[0] is 0 set y to 1101
					y = 4'b1101;
				else
					y = 4'b1110;			//if both a[1] and a[0] are 1 set y to 1110
		
	
endmodule