//   Author: Chris Thomas
//   Lab: Lab06
//   Project: Tx Rx
//   File Name: to_upper.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Checks if the key pressed received is a lower case letter and makes it upper case and sends it back.
//-----------------------------------------------------------------------------
//   Date: 03/11/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module to_upper(
	input clk,
	input [7:0] data_in,
	input new_data,
	output reg [7:0] data_out,
	output reg transmit
);

reg [3:0] count;

initial
	begin
		data_out <= 0;
		transmit <= 0;
		count <= 0;
	end
	
	always @(posedge clk)
		begin
			if(new_data == 1 || count != 0)					//check if we have new data or are in the middle of flagging for trasnmit
				begin
					if(data_in > 96 && data_in < 123)
						begin
							data_out <= data_in - 32;			//if its a lower case letter subtract to make it upper case
							transmit <= 1;
							count <= count + 1;
						end
					else
						begin
							data_out <= data_in;					//if its not a lower case letter just send back what was received
							transmit <= 1;
							count <= count + 1;
						end
				end
			else
				begin
					transmit <= 0;									//if not new data or in the middle set transmit to 0
				end
		end
endmodule