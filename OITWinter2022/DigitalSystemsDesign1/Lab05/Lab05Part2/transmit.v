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
	output reg data_out = 1
);

reg [2:0] state;
reg [3:0] count;
reg [18*8-1:0] message  = "Hello Chris Thomas";
reg [4:0] message_count;
reg [7:0] data;

parameter 	Length = 18,
				Idle = 3'b000,
				Start = 3'b001,
				Transmit = 3'b010,
				Parity = 3'b011,
				Stop = 3'b100;

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
							message_count <= 0;
							if(but)
								begin
									state <= Start;
								end
							else
								begin
									data_out <= 1;
									state <= Idle;						//stay in idle state until button is pushed
								end
						end
					Start:
						begin
							count <= 0;
							case(message_count)
								5'b00000 : data <= message[143:136];
								5'b00001 : data <= message[135:128];
								5'b00010 : data <= message[127:120];
								5'b00011 : data <= message[119:112];
								5'b00100 : data <= message[111:104];
								5'b00101 : data <= message[103:96];
								5'b00110 : data <= message[95:88];
								5'b00111 : data <= message[87:80];
								5'b01000 : data <= message[79:72];
								5'b01001 : data <= message[71:64];
								5'b01010 : data <= message[63:56];
								5'b01011 : data <= message[55:48];
								5'b01100 : data <= message[47:40];
								5'b01101 : data <= message[39:32];
								5'b01110 : data <= message[31:24];
								5'b01111 : data <= message[23:16];
								5'b10000 : data <= message[15:8];
								5'b10001 : data <= message[7:0];
							endcase	
							data_out <= 0;								//drive the start bit low to start transmit
							state <= Transmit;
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
									message_count <= message_count + 1;
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
							if(message_count < 5'b10010)
								begin
									state <= Start;
								end
							else
								begin
									state <= Idle;
								end
						end
			endcase
		end
endmodule