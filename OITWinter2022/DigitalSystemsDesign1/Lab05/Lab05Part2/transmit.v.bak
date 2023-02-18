//   Author: Chris Thomas
//   Lab: Lab05
//   Project: UART Transmit
//   File Name: transmit.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Create a state machine that handles transmitting the data whe necessary.
//-----------------------------------------------------------------------------
//   Date: 03/5/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module transmit(
	input clk,
	input but,
	input [7:0] data,
	output reg data_out = 1
);

reg [1:0] state;
reg [3:0] count;

parameter 	Idle = 2'b00,
				Transmit = 2'b01,
				Parity = 2'b10,
				Stop = 2'b11;

initial
	begin
		data_out <= 1;
		state <= Idle;
		count <= 0;
	end
		
			
	always @(posedge clk)
		begin
			case(state)
					Idle:													//idle state to reset outputs and wait for button push
						begin
							data_out <= 1;
							count <= 0;
							if(but)
								begin
									data_out <= 0;						//drive the start bit low to start transmit
									state <= Transmit;
								end
							else
								begin
									data_out <= 1;
									state <= Idle;						//stay in idle state until button is pushed
								end
						end
					Transmit:
						begin
							data_out <= data[count];				//output the data bits
							if(count < 4'b1000)
								begin
									count <= count + 1;				//if count is less then the number of data bits
									state <= Transmit;				//increment count and stay in push state
								end
							else
								begin	
									state <= Parity;					//Move to wait state
								end
						end
					Parity:
						begin
							data_out <= (data[0] ^ data[1] ^ data[2] ^ data[3] ^ data[4] ^ data[5] ^ data[6] ^ data[7]);	
							state <= Stop;								//return to idle state
						end
					Stop:
						begin
							data_out <= 1;
							state <= Idle;
						end
			endcase
		end
endmodule