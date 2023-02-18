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
module winner(
input [2:0] pos1,
input [2:0] pos2,
input [2:0] pos3,
input [2:0] pos4,
input [2:0] pos5,
input [2:0] pos6,
input [2:0] pos7,
input [2:0] pos8,
input [2:0] pos9,
output redWins,
output blueWins
);



//Student writes winner logic 
assign redWins = (pos1[0] & pos2[0] & pos3[0]) 				//Checks for all possible win conditions all 3 vertical, all 3 horizontal, and both diagonal options for red
					& (pos4[0] & pos5[0] & pos6[0]) 
					& (pos7[0] & pos8[0] & pos9[0]) 
					& (pos1[0] & pos4[0] & pos7[0]) 
					& (pos2[0] & pos5[0] & pos8[0]) 
					& (pos3[0] & pos6[0] & pos9[0]) 
					& (pos1[0] & pos5[0] & pos9[0]) 
					& (pos3[0] & pos5[0] & pos7[0]);
	
assign blueWins = (pos1[1] & pos2[1] & pos3[1]) 			//Checks for all possible win conditions all 3 vertical, all 3 horizontal, and both diagonal options for blue
					& (pos4[1] & pos5[1] & pos6[1]) 
					& (pos7[1] & pos8[1] & pos9[1]) 
					& (pos1[1] & pos4[1] & pos7[1]) 
					& (pos2[1] & pos5[1] & pos8[1]) 
					& (pos3[1] & pos6[1] & pos9[1]) 
					& (pos1[1] & pos5[1] & pos9[1]) 
					& (pos3[1] & pos5[1] & pos7[1]);
endmodule 