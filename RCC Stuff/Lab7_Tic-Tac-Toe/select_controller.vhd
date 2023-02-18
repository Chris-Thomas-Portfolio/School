--------------------------------------------------------------------------------
--
--   FileName:         select_controller.vhd
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
-- Verilog equivalent
-- module select_controller(
-- input button_clock,
-- input reset,
-- input sel,
-- output [9:0] offsetx,
-- output [9:0] offsety,
-- output [3:0] counter
-- );
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


ENTITY select_controller IS

PORT(
		button_clock		: IN STD_LOGIC;
		reset			: IN STD_LOGIC;
		sel   		: IN STD_LOGIC;
		offsetx	: OUT integer RANGE 0 to 1024;
		offsety	: OUT integer RANGE 0 to 1024;
		position	: OUT integer RANGE 0 to 16
);

END select_controller;

ARCHITECTURE behavioral of select_controller IS
signal CLOCK_OUT: std_logic;
signal count_reg: integer RANGE 0 to 8;

BEGIN

	PROCESS(button_clock)
		--VARIABLE count	: INTEGER RANGE 0 to 58333;
		BEGIN
			IF(rising_edge(button_clock)) THEN
				IF(reset = '1') THEN 
					count_reg <= 1;
					offsetx <= 10;
					offsety <= 0;
				ELSIF(sel = '0') THEN 
					count_reg <= count_reg + 1;
					IF(count_reg = 9) THEN
						count_reg <= 1;
						offsetx <= 10;
						offsety <= 0;
					ELSE 
						case count_reg is
							when 0 => offsetx <= 10; offsety <= 0;
							when 1 => offsetx <= 220; offsety <= 0;
							when 2 => offsetx <= 430; offsety <= 0;
							when 3 => offsetx <= 10; offsety <= 155;
							when 4 => offsetx <= 220; offsety <= 155;
							when 5 => offsetx <= 430; offsety <= 155;
							when 6 => offsetx <= 10; offsety <= 320;
							when 7 => offsetx <= 220; offsety <= 320;
							when 8 => offsetx <= 430; offsety <= 320;
							when others => offsetx <= 10; offsety <= 0;
						
						end case;
				END IF;
					END IF;
				
		
			END IF;
	END PROCESS;
	
	position <= count_reg;

END behavioral;


-- R1 Y = 0
-- R2 Y = 155
-- R3 Y = 320
-- C1 X = 10
-- C2 X = 220
-- C3 X = 430

