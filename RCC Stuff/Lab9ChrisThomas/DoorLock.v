module DoorLock(clk, reset, btn, ld, LEDR);

	input clk, reset;
	input [2:0] btn;
	output [5:4] ld; 
	output [7:0] LEDR;
	reg [3:0] state;
	reg [5:4] ld;
	
	parameter Empty = 4'b0000,
				 Two = 4'b0001,
				 TwoZero = 4'b0010,
				 TwoZeroOne = 4'b0011,
				 TwoZeroOneZero = 4'b0100,
				 EmptyFail = 4'b0101,
				 TwoFail = 4'b0110,
				 TwoZeroFail = 4'b0111,
				 TwoZeroOneFail = 4'b1000;
	
	assign LEDR[7:0] = 8'b0;
		
		always @(posedge clk, posedge reset)
			begin
				if(reset)									//if reset is high set state to Empty and the outputs to low
				begin
					state <= Empty;
					ld[5:4] <= 0;
				end
				
				else
				begin
					case(state)								//if reset is low move onto the cases
					Empty:
					begin
						if(btn[2])							//if btn2 is high move to the Two state
						begin
							state <= Two;
							ld[5:4] <= 0;
						end
						else
						begin									//if it is not move to the EmptyFail state
							state <= EmptyFail;
							ld[5:4] <= 0;
						end
					end
					
					Two:
					begin
						if(btn[0])							//if btn0 is high move on the the TwoZero state
						begin
							state <= TwoZero;
							ld[5:4] <= 0;
						end
						else
						begin									//if it is not move on to the TwoFail state
							state <=TwoFail;
							ld[5:4] <= 0;
						end
					end
					
					TwoZero:
					begin
						if(btn[1])							//if btn1 is high move on to the TwoZeroOne state
						begin
							state <= TwoZeroOne;
							ld[5:4] <= 0;
						end
						else
						begin
							state <= TwoZeroFail;		//if it is not move on to the TwoZeroFail state
							ld[5:4] <= 0;
						end
					end
					
					TwoZeroOne:
					begin
						if(btn[0])							//if btn0 is high move on to the TwoZeroOneZero state
						begin
							state <= TwoZeroOneZero;
							ld[5:4] <= 0;
						end
						else
						begin
							state <= TwoZeroOneFail;	//if it is not move on to the TwoZeroOneFail state
							ld[5:4] <= 0;
						end
					end
					
					TwoZeroOneZero:
					begin
						if(btn[2])							//if btn2 is high return to the Two state and set ld5 to high indicating the sequence was input properly 
						begin
							state <= Two;
							ld[5] <= 1;
							ld[4] <= 0;
						end
						else
						begin
							state <= Empty;				//if not return to state Empty and set ld4 to high indicating the sequence was input improperly
							ld[4] <= 1;
							ld[5] <= 0;
						end
					end
			
/**********************************************************************************************************************************************************************************************************************
	It was a design decision on my part to not inform the user immediately when the sequence failed I chose to do this as it would be more difficult to guess the code if you did not know where you made the mistake.
***********************************************************************************************************************************************************************************************************************/	
					EmptyFail:								//if the sequence is put in improperly at any point there is no need to check further inputs so continue through the fail states
					begin
						state <= TwoFail;
						ld[5:4] <= 0;
					end
					
					TwoFail:
					begin
						state <= TwoZeroFail;			//continue through fail states
						ld[5:4] <= 0;
					end
					
					TwoZeroFail:
					begin
						state <= TwoZeroOneFail;		//continue through fail states
						ld[5:4] <= 0;
					end
					
					TwoZeroOneFail:						//finally after a fifth input let the user know the sequence was input improperly by setting 
					begin
						state <= Empty;
						ld[4] <= 1;
						ld[5] <= 0;
					end
				endcase
			end
		end
endmodule
