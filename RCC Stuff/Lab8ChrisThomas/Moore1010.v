module Moore1010(clk, reset, in, out, LEDR);

	input clk, reset, in;
	output out;
	output [8:0] LEDR;
	reg [2:0] state;
	reg out;

	parameter Zero = 3'b000,
				 One = 3'b001,
				 OneZero = 3'b010,
				 OneZeroOne = 3'b011,
				 OneZeroOneZero = 3'b100;

	assign LEDR[8:0] = 9'b0;

		always @(posedge clk, posedge reset)
			begin
				if(reset)								//if reset is high set state back to beginning state Zero
				begin
					state <= Zero;
				end
				
				else
				begin										//if reset is low move onto state cases
					case(state)
					Zero:
					begin
						if (in)							//if in is high move to state One
						begin
							state <= One;
						end
						else
						begin
							state <= Zero;				//if in is low stay at state Zero
						end
					end
					
					One:
					begin
						if (in)							//if in is high stay at state One
						begin
							state <= One;
						end
						else
						begin								//if in is low move to state OneZero
							state <= OneZero;
						end
					end
					
					OneZero:
					begin
						if (in)							//if in is high move to state OneZeroOne
						begin
							state <= OneZeroOne;
						end
						else
						begin								//if in is low stay at state OneZero
							state <= OneZero;
						end
					end
					
					OneZeroOne:
					begin
						if (in)							//if in is high stay at state OneZeroOne
						begin
							state <= OneZeroOne;
						end
						else
						begin								//if in is low move to state OneZeroOneZero
							state <= OneZeroOneZero;
						end
					end
					
					OneZeroOneZero:
					begin
						if (in)							//if in is high move to stat OneZero
						begin
							state <= OneZero;
						end
						else
						begin
							state <= Zero;				//if in is low move to state Zero
						end
					end
				endcase
			end
		end

		always @(state)
			begin
				case(state)								//only output a high once state OneZeroOneZero is reached.
					Zero:
					begin
						out <= 0;
					end
					
					One:
					begin 
						out <= 0;
					end
					
					OneZero:
					begin
						out <= 0;
					end
					
					OneZeroOne:
					begin
						out <= 0;
					end
					
					OneZeroOneZero:
					begin
						out <= 1;
					end
				endcase
			end

endmodule