/*
--------------------------------------------------------------------------------
--
--   FileName:         gamelogic.v
--   Dependencies:     none
--   Design Software:  Quartus Prime Standard Edition
--
--   HDL CODE IS PROVIDED "AS IS."
--
--   Version History
--   Version 1.0 27.10.17 Kevin Pintong
--     Initial Public Release
--
--------------------------------------------------------------------------------
*/
module gamelogic(
input [3:0] position,
input vga_clock,
input place,
input reset,
output reg [2:0]  pos1,	//pos keeps track of the following: 000 = empty; 010 = blue; 001 = red
output reg [2:0]  pos2,
output reg [2:0]  pos3,
output reg [2:0]  pos4,
output reg[2:0]  pos5,
output reg[2:0]  pos6,
output reg[2:0]  pos7,
output reg[2:0]  pos8,
output reg[2:0]  pos9
);

reg [1:0]state;


			 
	always @(posedge vga_clock, posedge reset)			//decided to make a FSM to control whose turn it is
	begin
		if(reset)													//check for reset
		begin
			state <= 1'b0;
		end
		else
		begin
			case(state)
			1'b0:														//red teams state
			begin
				if(!place)
				begin
					if(position == 4'b0000)						//check the position input for which pos needs to be checked for already taken
					begin
						if(pos1[2] == 1'b0)						
						begin											
							pos1[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos1[0] = 1'b1;
							state <= 1'b1;
						end
					end
					else if(position == 4'b0001)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos2[2] == 1'b0)
						begin
							pos2[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos2[0] = 1'b1;
							state <= 1'b1;
						end
					end
					else if(position == 4'b0010)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos3[2] == 1'b0)
						begin
							pos3[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos3[0] = 1'b1;
							state <= 1'b1;
						end
					end
					else if(position == 4'b0011)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos4[2] == 1'b0)
						begin
							pos4[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos4[0] = 1'b1;
							state <= 1'b1;
						end
					end
					else if(position == 4'b0100)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos5[2] == 1'b0)
						begin
							pos5[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos5[0] = 1'b1;
							state <= 1'b1;
						end
					end	
					else if(position == 4'b0101)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos6[2] == 1'b0)
						begin
							pos6[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos6[0] = 1'b1;
							state <= 1'b1;
						end
					end
					else if(position == 4'b0110)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos7[2] == 1'b0)
						begin
							pos7[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos7[0] = 1'b1;
							state <= 1'b1;
						end
					end
					else if(position == 4'b0111)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos8[2] == 1'b0)
						begin
							pos8[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos8[0] = 1'b1;
							state <= 1'b1;
						end
					end
					else if(position == 4'b1000)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos9[2] == 1'b0)
						begin
							pos9[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos9[0] = 1'b1;
							state <= 1'b1;
						end
					end
				end
			end
			1'b1:
			begin
				if(!place)
				begin
					if(position == 4'b0000)						//check the position input for which pos needs to be checked for already taken
					begin
						if(pos1[2] == 1'b0)
						begin
							pos1[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos1[1] = 1'b1;
							state <= 1'b0;
						end
					end
					else if(position == 4'b0001)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos2[2] == 1'b0)
						begin
							pos2[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos2[1] = 1'b1;	
							state <= 1'b0;
						end
					end
					else if(position == 4'b0010)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos3[2] == 1'b0)
						begin
							pos3[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos3[1] = 1'b1;
							state <= 1'b0;
						end
					end
					else if(position == 4'b0011)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos4[2] == 1'b0)
						begin
							pos4[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos4[1] = 1'b1;
							state <= 1'b0;
						end
					end
					else if(position == 4'b0100)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos5[2] == 1'b0)
						begin
							pos5[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos5[1] = 1'b1;
							state <= 1'b0;
						end
					end
					else if(position == 4'b0101)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos6[2] == 1'b0)
						begin
							pos6[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos6[1] = 1'b1;
							state <= 1'b0;
						end
					end
					else if(position == 4'b0110)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos7[2] == 1'b0)
						begin
							pos7[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos7[1] = 1'b1;
							state <= 1'b0;
						end
					end
					else if(position == 4'b0111)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos8[2] == 1'b0)
						begin
							pos8[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos8[1] = 1'b1;
							state <= 1'b0;
						end
					end
					else if(position == 4'b1000)				//check the position input for which pos needs to be checked for already taken
					begin
						if(pos9[2] == 1'b0)
						begin
							pos9[2] = 1'b1;						//if it is not taken change it to taken and set it to appropriate color.
							pos9[1] = 1'b1;
							state <= 1'b0;
						end
					end
				end
			end
		endcase
	end
end

endmodule 