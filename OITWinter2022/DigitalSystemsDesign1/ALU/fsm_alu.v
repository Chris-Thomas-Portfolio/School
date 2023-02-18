module fsm_alu(
input [2:0] opcode,
input [3:0] a,
input [3:0] b,
input clk, reset, go,
output reg [4:0] result,
output reg cout, led_idle, led_ready, led_done
);

reg [3:0] state;

parameter Idle 		= 4'b0000,
          Add 			= 4'b0001,
			 Subtract 	= 4'b0010,
          NOTA 		= 4'b0011,
			 NOTB 		= 4'b0100,
			 AND 			= 4'b0101,
			 OR 			= 4'b0110,
			 XOR 			= 4'b0111,
			 XNOR 		= 4'b1000;
initial 
	begin
		state <= Idle;
	end
	
	
always @(posedge clk)
    begin
        if(reset)
            begin
                led_idle <= 1;
                state <= Idle;
            end
        else
				case(state)
					Idle:
						begin
							led_idle <= 0;
							cout <= 0;
							led_ready <= 1;
							led_done <= 0;
							result <= 0;
							if(go)
								begin
									case(opcode)
										3'b000:
											begin
												state <= Add;
											end
										3'b001:
											begin
												state <= Subtract;
											end
										3'b010:
											begin
												state <= NOTA;
											end
										3'b011:
											begin
												state <= NOTB;
											end
										3'b100:
											begin
												state <= AND;
											end
										3'b101:
											begin
												state <= OR;
											end
										3'b110:
											begin
												state <= XOR;
											end
										3'b111:
											begin
												state <= XNOR;
											end
										default:
											begin
												state <= Idle;
											end
									endcase
								end
						end
               Add:
                  begin
							result <= a + b;
							led_done <= 1;
							led_ready <= 0;
							cout <= result[4];
							state <= Idle;
						end
               Subtract:
                  begin
							result <= a - b;
							led_done <= 1;
							led_ready <= 0;
							state <= Idle;
                  end
               NOTA:
						begin
							result <= ~a;
							led_done <= 1;
							led_ready <= 0;
							state <= Idle;
						end
               NOTB:
						begin
							result <= ~b;
							led_done <= 1;
							led_ready <= 0;
							state <= Idle;
                  end
               AND:
						begin
							result <= a & b;
							led_done <= 1;
							led_ready <= 0;
							state <= Idle;
						end
               OR:
						begin
							result <= a | b;
							led_done <= 1;
							led_ready <= 0;
							state <= Idle;
						end
               XOR:
						begin
							result <= a ^ b;
							led_done <= 1;
							led_ready <= 0;
							state <= Idle;
						end
               XNOR:
						begin
							result <= ~(a ^ b);
							led_done <= 1;
							led_ready <= 0;
							state <= Idle;
						end
            endcase
    end


endmodule