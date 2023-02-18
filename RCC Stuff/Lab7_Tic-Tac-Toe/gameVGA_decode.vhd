--------------------------------------------------------------------------------
--
--   FileName:         gameVGA_decode.vhd
--   Dependencies:     none
--   Design Software:  Quartus Prime
--
--   HDL CODE IS PROVIDED "AS IS."  
--
--   Version History
--   Version 1.0 26.10.17 Kevin Pintong
--
--------------------------------------------------------------------------------
-- Verilog equivlaent
-- module gameVGA_decode(
-- input [9:0] xpos,
-- input [9:0] ypos,
-- input [9:0] offsetx,
-- input [9:0] offsety,
-- input redWins,
-- input blueWins,
-- input ren1,
-- input ren2,
-- input ren3,
-- input ren4,
-- input ren5,
-- input ren6,
-- input ren7,
-- input ren8,
-- input ren9,
-- input bluen1,
-- input bluen2,
-- input bluen3,
-- input bluen4,
-- input bluen5,
-- input bluen6,
-- input bluen7,
-- input bluen8,
-- input bluen9
-- output [3:0] red,
-- output [3:0] blue,
-- output [3:0] green
-- );

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

ENTITY gameVGA_decode IS
   PORT(
    xpos     : IN  integer RANGE 0 to 1024;  
	 ypos     : IN  integer RANGE 0 to 1024;  
	 offsetx  : IN  integer RANGE 0 to 1024;   
	 offsety  : IN  integer RANGE 0 to 1024;    
	 redWins  : IN  STD_LOGIC;
	 blueWins : IN  STD_LOGIC;
	 ren1		 : IN  STD_LOGIC;
	 ren2		 : IN  STD_LOGIC;
	 ren3		 : IN  STD_LOGIC;
	 ren4		 : IN  STD_LOGIC;
	 ren5		 : IN  STD_LOGIC;
	 ren6		 : IN  STD_LOGIC;
	 ren7		 : IN  STD_LOGIC;
	 ren8		 : IN  STD_LOGIC;
	 ren9		 : IN  STD_LOGIC;
	 bluen1	 : IN  STD_LOGIC;
	 bluen2	 : IN  STD_LOGIC;
	 bluen3	 : IN  STD_LOGIC;
	 bluen4	 : IN  STD_LOGIC;
	 bluen5	 : IN  STD_LOGIC;
	 bluen6	 : IN  STD_LOGIC;
	 bluen7	 : IN  STD_LOGIC;
	 bluen8	 : IN  STD_LOGIC;
	 bluen9	 : IN  STD_LOGIC;
	 red		 : OUT  STD_LOGIC_VECTOR(3 downto 0);
	 blue	    : OUT  STD_LOGIC_VECTOR(3 downto 0);
	 green    : OUT  STD_LOGIC_VECTOR(3 downto 0)
	 );
END gameVGA_decode;

ARCHITECTURE logic OF gameVGA_decode IS
	SIGNAL hatchy : STD_LOGIC;
	SIGNAL hatchx : STD_LOGIC;
	SIGNAL red1: STD_LOGIC;
	signal red2: STD_LOGIC;
	SIGNAL red3: STD_LOGIC;
	signal red4: STD_LOGIC;
	SIGNAL red5: STD_LOGIC;
	signal red6: STD_LOGIC;
	SIGNAL red7: STD_LOGIC;
	signal red8: STD_LOGIC;
	signal red9: STD_LOGIC;
	SIGNAL blue1: STD_LOGIC;
	signal blue2: STD_LOGIC;
	SIGNAL blue3: STD_LOGIC;
	signal blue4: STD_LOGIC;
	SIGNAL blue5: STD_LOGIC;
	signal blue6: STD_LOGIC;
	SIGNAL blue7: STD_LOGIC;
	signal blue8: STD_LOGIC;
	signal blue9: STD_LOGIC;
	signal sel: STD_LOGIC;

BEGIN

--Draw the crossmembers
   
   hatchy <= '1' when ((ypos >= 144 and ypos <= 164) or (ypos>310 and ypos <330)) and xpos >20 and xpos <620 else
			    '0';
   hatchx <= '1' when ((xpos > 200 and xpos <220) or (xpos>420 and xpos <440)) and ypos <460 and ypos >20 else 
				 '0';
-- row 1
 	red1 <= '1' when (ren1 = '1') and (ypos > 10 and ypos < 135) and (xpos >30 and xpos < 190) else '0';
 	red2 <= '1' when (ren2 = '1') and (ypos > 10 and ypos < 135) and (xpos >240 and xpos < 400) else '0';
 	red3 <= '1' when (ren3 = '1') and (ypos > 10 and ypos < 135) and (xpos >450 and xpos < 610) else '0';
-- row 2
 	red4 <= '1' when (ren4 = '1') and (ypos > 175 and ypos < 300) and (xpos >30 and xpos < 190) else '0';
 	red5 <= '1' when (ren5 = '1') and (ypos > 175 and ypos < 300) and (xpos >240 and xpos < 400) else '0';
 	red6 <= '1' when (ren6 = '1') and (ypos > 175 and ypos < 300) and (xpos >450 and xpos < 610) else '0';
-- row 3
 	red7 <= '1' when (ren7 = '1') and (ypos > 340 and ypos < 470) and (xpos >30 and xpos < 190) else '0';
 	red8 <= '1' when (ren8 = '1') and (ypos > 340 and ypos < 470) and (xpos >240 and xpos < 400) else '0';
 	red9 <= '1' when (ren9 = '1') and (ypos > 340 and ypos < 470) and (xpos >450 and xpos < 610) else '0';

-- row 1
 blue1 <= '1' when (bluen1 = '1') and (ypos > 10 and ypos < 135) and (xpos >30 and xpos < 190) else '0';
 blue2 <= '1' when (bluen2 = '1') and (ypos > 10 and ypos < 135) and (xpos >240 and xpos < 400) else '0';
 blue3 <= '1' when (bluen3 = '1') and (ypos > 10 and ypos < 135) and (xpos >450 and xpos < 610) else '0';
-- row 2 
 blue4 <= '1' when (bluen4 = '1') and (ypos > 175 and ypos < 300) and (xpos >30 and xpos < 190) else '0';
 blue5 <= '1' when (bluen5 = '1') and (ypos > 175 and ypos < 300) and (xpos >240 and xpos < 400) else '0';
 blue6 <= '1' when (bluen6 = '1') and (ypos > 175 and ypos < 300) and (xpos >450 and xpos < 610) else '0';
-- row 3
 blue7 <= '1' when (bluen7 = '1') and (ypos > 340 and ypos < 470) and (xpos >30 and xpos < 190) else '0';
 blue8 <= '1' when (bluen8 = '1') and (ypos > 340 and ypos < 470) and (xpos >240 and xpos < 400) else '0';
 blue9 <= '1' when (bluen9 = '1') and (ypos > 340 and ypos < 470) and (xpos >450 and xpos < 610) else '0';

 sel <= '1' when ypos > offsety and ypos < (165 + offsety) and (xpos > offsetx) and xpos < (200 + offsetx) else '0';


-- colorize everything

red(3) <=  (not blueWins) and (hatchy  or  hatchx  or red1 or 	red2 or 	red3 or 	red4 or 	red5 or 	red6 or 	red7 or 	red8 or 	red9);
red(2) <= (not blueWins) and (	red1 or 	red2 or 	red3 or 	red4 or 	red5 or 	red6 or 	red7 or 	red8 or 	red9);
red(1) <= (not blueWins) and (	red1 or 	red2 or 	red3 or 	red4 or 	red5 or 	red6 or 	red7 or 	red8 or 	red9); 
red(0) <= (not blueWins) and (	red1 or 	red2 or 	red3 or 	red4 or 	red5 or 	red6 or 	red7 or 	red8 or 	red9);			
green(3) <= (not redWins) and (not blueWins) and (hatchy  or  hatchx  or  sel);
green(2) <= (not redWins) and (not blueWins) and (sel);
green(1) <= '0';
green(0) <= '0';
blue(3)  <= (not redWins) and (hatchy  or  hatchx  or blue1 or blue2 or blue3 or blue4 or blue5 or blue6 or blue7 or blue8 or blue9);
blue(2)  <=	(not redWins) and (blue1 or blue2 or blue3 or blue4 or blue5 or blue6 or blue7 or blue8 or blue9);
blue(1)  <=	(not redWins) and (blue1 or blue2 or blue3 or blue4 or blue5 or blue6 or blue7 or blue8 or blue9);
blue(0)  <=	(not redWins) and (blue1 or blue2 or blue3 or blue4 or blue5 or blue6 or blue7 or blue8 or blue9);



END logic;
		





