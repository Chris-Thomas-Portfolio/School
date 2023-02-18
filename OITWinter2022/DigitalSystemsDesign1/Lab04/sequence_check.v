module sequence_check(
	input clk,
	input times_up,
	input [15:0] sequence,
	input new_seq,
	output reg unlock,
	output reg error,
	output reg start_time
);

reg [1:0] state;

/* Creation of states*/
parameter Idle 	= 2'b00,
			 Check	= 2'b01,
			 Unlock 	= 2'b10,
			 Error 	= 2'b11;

/*Initial block for testbench*/		 
initial
	begin
		unlock <= 0;
		error <= 0;
		start_time <= 0;
		state <= Idle;
	end

	always @(posedge clk)
		begin
			case(state)
				Idle:
					begin
						unlock <= 0;
						error <= 0;
						if(new_seq)
							begin
								state <= Check;
							end
						else
							begin
								state <= Idle;
							end
					end
				Check:
					case(sequence)
						16'h1234 : state <= Unlock;
						16'hABCD : state <= Unlock;
						16'h1122 : state <= Unlock;
						16'h1010 : state <= Unlock;
						16'h123A : state <= Unlock;
						16'h2580 : state <= Unlock;
						default 	: state <= Error;
					endcase
				Unlock:
					begin
						start_time <= 1;
						unlock <= 1;
						if(times_up == 1)
							begin
								unlock <= 0;
								start_time <= 0;
								state <= Idle;
							end	
						else
							begin
								unlock <= 1;
							end
					end
				Error:
					begin
						start_time <= 1;
						error <= 1;
						if(times_up == 1)
							begin
								error <= 0;
								start_time <= 0;
								state <= Idle;
							end	
						else
							begin
								error <= 1;
							end
					end
			endcase
		end	
endmodule