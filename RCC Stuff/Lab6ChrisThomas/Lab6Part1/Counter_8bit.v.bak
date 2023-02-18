module Counter_8bit(
	input [1:0] SW,
	input KEY0,
	output [0:6] HEX0, HEX1
	);
	
	//Connections for Clock and Reset to Outside World
	wire Clock;
	wire Resetn;
	assign Clock = KEY0;
	assign Resetn = SW[0];  // active low clear
	
	// 8-bit counter based on T-flip flops
	wire [7:0] Count;
	wire [7:0] Enable;
	
	//Instantiation statements for T Flip-Flops
	assign Enable[0] = SW[1];
	ToggleFF ff0(Enable[0], Clock, Resetn, Count[0]); 
	assign Enable[1] = Count[0] & Enable[0];   // add and gates inbetween ffs
	ToggleFF ff1(Enable[1], Clock, Resetn, Count[1]);
	assign Enable[2] = Count[1] & Enable[1];   
	ToggleFF ff2(Enable[2], Clock, Resetn, Count[2]);
	assign Enable[3] = Count[2] & Enable[2];   
	ToggleFF ff3(Enable[3], Clock, Resetn, Count[3]);
	assign Enable[4] = Count[3] & Enable[3];   
	ToggleFF ff4(Enable[4], Clock, Resetn, Count[4]);
	assign Enable[5] = Count[4] & Enable[4];   
	ToggleFF ff5(Enable[5], Clock, Resetn, Count[5]);
	assign Enable[6] = Count[5] & Enable[5];   
	ToggleFF ff6(Enable[6], Clock, Resetn, Count[6]);
	assign Enable[7] = Count[6] & Enable[6];   
	ToggleFF ff7(Enable[7], Clock, Resetn, Count[7]);
	
	// drive the displays
	hex7seg digit1 (Count[7:4], HEX1);
	hex7seg digit0 (Count[3:0], HEX0);
	
endmodule  // Counter_8bit