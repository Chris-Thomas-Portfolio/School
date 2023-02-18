module LightControllerChrisThomas(x1,x2,f);

	input x1, x2;				//inputs for controller
	output f;					//output for controller
	
	assign f=(x1 & ~x2) | (~x1 & x2);  //assign output for controller
	
endmodule