
--------------------------------------------------------------------------------
--
--   FileName:         button_clock.vhd
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


ENTITY button_clock IS

PORT(
		CLOCK_50			: IN STD_LOGIC;
		CLOCK_BUTTON	: OUT STD_LOGIC
);

END button_clock;

ARCHITECTURE behavioral of button_clock IS
signal CLOCK_OUT: std_logic;

BEGIN

	PROCESS(CLOCK_50)
		VARIABLE count	: INTEGER RANGE 0 to 2500000;
		BEGIN
			IF(rising_edge(CLOCK_50)) THEN
				count := count + 1;
				IF(count = 2500000) THEN
					CLOCK_OUT <= not CLOCK_OUT;
					count:= 0;
					
				END IF;
			END IF;
	END PROCESS;
	
	CLOCK_BUTTON <= CLOCK_OUT;


END behavioral;