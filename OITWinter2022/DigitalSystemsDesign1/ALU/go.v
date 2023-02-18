module go(
	input clk,
	input reset,
	input go,
	input [3:0] data_in,
	output reg [3:0] data,
	output reg wait_led,
	output reg state_change
);


reg state;

parameter Idle = 1'b0,
			 Go 	= 1'b1;
			 
initial
	begin
		state <= Idle;
		wait_led <= 0;
		state_change <= 0;
		data <= 0;
	end
	

	always @(posedge clk)
		begin
			if(reset)
				begin
					wait_led <= 0;
					data <= 0;
					state_change <= 0;
					state <= Idle;
				end
			else
				begin
					case(state)
						Idle:
							begin
								state_change <= 0;
								if(go)
									begin
										data <= data_in;
										wait_led <= 1;
										state <= Go;
									end
								else
									begin
										state <= Idle;
									end
							end
						Go:
							if(~go)
								begin
									state_change <= 1;
									wait_led <= 0;
									state <= Idle;
								end
							else
								begin
									state <= Go;
								end
					endcase
				end
		end
endmodule