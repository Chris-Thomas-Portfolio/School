//   Author: Chris Thomas
//   Lab: Final1
//   Project: Final
//   File Name: taillight_FSM.v
//   List of other files used: N/A
//-----------------------------------------------------------------------------
//   Description of the Code:
//   Creates a FSM to handle the different functionality of the taillights.
//-----------------------------------------------------------------------------
//   Date: 03/12/2022
//   Version: 1.0
//   Revision: N/A
//-----------------------------------------------------------------------------
module taillight_FSM(
	input clk,
	input left,
	input right,
	input bk,
	input haz,
	output reg [5:0] led
);

reg [2:0] state;

parameter	Idle 	= 3'b000,
				Left 	= 3'b001,
				Right = 3'b010,
				BK 	= 3'b011,
				HAZ 	= 3'b100,
				LBK	= 3'b101,
				RBK	= 3'b110;
				
/*Initialize block for testbench*/	
initial
		begin
			state <= Idle;
			led <= 0;
		end
		
	always @(posedge clk)	
		begin
			if(haz)
				begin
					state <= HAZ;						//if haz is high go to hazard state
				end
			else
				begin
					if(left && right && bk)			//handle multiple input situations by going to Idle
						begin
							state <= Idle;
						end
					else if(left && bk)				//go to LBK state to handle brakes and left turn signal situation
						begin
							state <= LBK;
						end
					else if(right && bk)				//go to RBK state to handle brakes and right turn signal situation
						begin
							state <= RBK;
						end
					else if(right && left)			//if left and right turn signal are on simultaniously go to Idle
						begin
							state <= Idle;
						end
					else
						begin
							if(left)						//if only left turn signal is on go to Left state
								begin
									state <= Left;
								end
							else if(right)
								begin
									state <= Right;	//if only right turn signal is on go to Right state
								end
							else if(bk)
								begin
									state <= BK;		//if only brakes are on go to BK state
								end
							else
								begin
									state <= Idle;		//if none of these cases go to Idle state
								end
						end	
				end
		end
				
	always @(posedge clk)
		begin
			case(state)
				Idle:
					begin
						led <= 0;						//turn all lights off 
					end
				Left:
					begin
						led[2:0] <= 0;					//turn off right lights
						if(led[3])
							begin
								led[4] <= 1;			//if the first light is on turn the second light on
							end
						if(led[4])
							begin
								led[5] <= 1;			//if the second light is on turn the third on
							end
						if(led[5])
							begin
								led[3] <= 0;			//if all three lights are on turn them all off
								led[4] <= 0;
								led[5] <= 0;
							end
						else
							begin
								led[3] <= 1;			//if none of the lights are on turn the first one on
							end
					end
				Right:
					begin
						led[5:3] <= 0;					//turn off left lights 
						if(led[0])
							begin
								led[1] <= 1;			//if the first light is on turn the second light on		
							end
						if(led[1])
							begin
								led[2] <= 1;			//if the second light is on turn the third on
							end
						if(led[2])
							begin
								led[0] <= 0;			//if all three lights are on turn them all off
								led[1] <= 0;
								led[2] <= 0;
							end
						else
							begin
								led[0] <= 1;			//if none of the lights are on turn the first one on
							end
					end
				BK:
					begin
						led <= 6'b111111;				//turn all lights on for brake lights
					end
				HAZ:
					begin
						if(led != 0)
							begin
								led <= 0;				//reset lights back to off
							end
						else
							begin
								led <= 6'b111111;		//set all lights on
							end
					end
				LBK:
					begin
						if(led[3])
							begin
								led[4] <= 1;			//if the first light is on turn the second light on
								led[2:0] <= 3'b111;	//turn the right lights on for brake
							end
						if(led[4])
							begin
								led[5] <= 1;			//if the second light is on turn the third on
								led[2:0] <= 3'b111;	//turn the right lights on for brake
							end
						if(led[5])
							begin
								led[3] <= 0;			//if all three lights are on turn them all off
								led[4] <= 0;
								led[5] <= 0;
								led[2:0] <= 3'b111;	//turn the right lights on for brake
							end
						else
							begin
								led[3] <= 1;			//if none of the lights are on turn the first one on
								led[2:0] <= 3'b111;	//turn the right lights on for brake
							end
					end
				RBK:
					begin
						if(led[0])
							begin
								led[1] <= 1;			//if the first light is on turn the second light on
								led[5:3] <= 3'b111;	//turn the right lights on for brake
							end
						if(led[1])
							begin
								led[2] <= 1;			//if the second light is on turn the third on
								led[5:3] <= 3'b111;	//turn the right lights on for brake
							end
						if(led[2])
							begin
								led[0] <= 0;			//if all three lights are on turn them all off
								led[1] <= 0;
								led[2] <= 0;
								led[5:3] <= 3'b111;	//turn the right lights on for brake
							end
						else
							begin
								led[0] <= 1;			//if none of the lights are on turn the first one on
								led[5:3] <= 3'b111;	//turn the right lights on for brake
							end
					end
			endcase
		end
endmodule