//   Author: Chris Thomas
//   Lab: Lab06
//   Project: Tx Rx
//   File Name: receiver.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Handles the receiver protocols.
//-----------------------------------------------------------------------------
//   Date: 03/11/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module receiver(
	input clk,
	input data_in,
	output reg [7:0] data_out,
	output reg new_data
);

reg [1:0] state;
reg [3:0] count;
reg [3:0] clkCount;
reg [7:0] temp;
reg parity;
reg valid;

parameter	Idle		= 2'b00,
				Receive	= 2'b01,
				Parity	= 2'b10,
				Stop		= 2'b11;
				
/*Initial block for testbench*/
initial
	begin
		state <= Idle;
		count <= 0;
		clkCount <= 0;
		temp = 0;
		parity = 0;
		valid = 0;
	end
	always @(posedge clk)
		begin
			case(state)
				Idle:																
					begin
						count <= 0;
						clkCount <= 0;
						temp <= 0;
						new_data <= 0;
						if(~data_in)										//wait for start bit to go low
							begin
								if(&clkCount)								//check to see if we have sampled 16 times to move to Receive state
									begin
										clkCount <= 0;
										state <= Receive;
									end
								else
									begin
										clkCount <= clkCount + 1;		//increment count if not at 16 samples
										state <= Idle;
									end
							end
						else
							begin
								state <= Idle;								//stay in Idle state if the start bit is high
							end
					end
				Receive:
					begin
						if(count == 4'b1000)								//check if we have got all 8 bits if so move to Parity state
							begin
								count <= 0;
								clkCount <= 0;
								state <= Parity;
							end
						else
							begin
								if(&clkCount)								//check if we have met sample needs for bit
									begin
										count <= count + 1;
										clkCount <= 0;
										state <= Receive;
									end
								else if(clkCount == 8)					//mid way through sampling get stable data
									begin
										temp[count] <= data_in;
										clkCount <= clkCount + 1;
										state <= Receive;					//stay in Receive to finish 16 sample
									end
								else
									begin
										clkCount <= clkCount + 1;		
										state <= Receive;
									end
							end
					end
				Parity:
					begin
						parity <= (temp[0] ^ temp[1] ^ temp[2] ^ temp[3] ^ temp[4] ^ temp[5] ^ temp[6] ^ temp[7]);		//calculated parity
						if(&clkCount)
							begin
								if(parity == valid)						//if sampling complete compare calculated parity with sent parity
									begin
										clkCount <= 0;
										state <= Stop;
									end
								else
									begin
										state <= Idle;
									end
							end
						else if(clkCount == 8)							//sample the stable data
							begin
								valid <= data_in;
								clkCount <= clkCount + 1;
								state <= Parity;
							end
						else
							begin
								clkCount <= clkCount + 1;
								state <= Parity;
							end
							
					end
				Stop:
					begin
						if(&clkCount && valid)							//send temp out to data_out
							begin
								data_out <= temp;
								new_data <= 1;								//flag that new data is ready
								state <= Idle;
							end
						else
							begin
								if(clkCount == 8)							//sample the stable data
									begin
										valid <= data_in;
										clkCount <= clkCount + 1;
									end
								else
									begin
										clkCount <= clkCount + 1;
										state <= Stop;
									end
							end
					end
			endcase
		end

endmodule