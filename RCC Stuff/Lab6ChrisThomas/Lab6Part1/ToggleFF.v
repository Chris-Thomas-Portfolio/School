//Sub-module ToggleFF
module ToggleFF(T, Clock, Resetn, Q);
	input T, Clock, Resetn;
	output reg Q;

	always @ (posedge Clock)
		begin 
			if (!Resetn)  // clear is active low;
				Q <= 1'b0;  // use non-blocking assignments with sequential logic
			else if (T)		//If T is HIGH toggle Q
				Q <= !Q;
		end  // always

endmodule // ToggleFF