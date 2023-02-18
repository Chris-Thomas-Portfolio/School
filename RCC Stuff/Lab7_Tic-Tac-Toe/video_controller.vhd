
--------------------------------------------------------------------------------
--
--   FileName:         video_controller.vhd
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
-- module video_controller(
-- input vga_clock,
-- output hsyncOut,
-- output vsyncOut,
-- output [9:0] xposOut,
-- output [9:0] yposOut
-- );

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


ENTITY video_controller IS

PORT(
		vga_clock				: IN STD_LOGIC;
		hsyncOut				: OUT STD_LOGIC;
		vsyncOut				: OUT STD_LOGIC;
		xposOut 				: OUT INTEGER RANGE 0 to 1024;
		yposOut				: OUT INTEGER RANGE 0 to 1024
);

END video_controller;

ARCHITECTURE behavioral of video_controller IS
signal xpos: INTEGER RANGE 0 to 1024;
signal ypos: INTEGER RANGE 0 to 1024;
signal endline: STD_LOGIC;
signal hsync: STD_LOGIC;
signal vsync: STD_LOGIC;
BEGIN



	PROCESS(vga_clock) BEGIN
		IF(rising_edge(vga_clock)) THEN
			IF(xpos = 799) THEN
				endline <= '1'; 
			ELSE 
				endline <= '0'; 
			END IF;
		END IF;
	END PROCESS;

	PROCESS(vga_clock) BEGIN
		IF(rising_edge(vga_clock)) THEN
			IF(endline = '1') THEN
				xpos <= 0; 
			ELSE 
				xpos <= xpos + 1; 
			END IF;
		END IF;
	END PROCESS;

	
	PROCESS(vga_clock) BEGIN
		IF(rising_edge(vga_clock)) THEN
			IF(endline = '1') THEN
				IF(ypos = 520) THEN
					ypos <= 0; 
				ELSE 
					ypos <= ypos + 1; 
				END IF;
			END IF;
		END IF;
	END PROCESS;
	
	
	PROCESS(vga_clock) BEGIN
		IF(rising_edge(vga_clock)) THEN
			
			IF((xpos > 664) and (xpos <= 759)) THEN
				hsync <= '0';
			ELSE 
				hsync <= '1';
			END IF;
			
			IF((ypos = 490) or (ypos = 491)) THEN 
				vsync <= '0';
			ELSE 
				vsync <= '1';
			END IF;
			
		END IF;
	END PROCESS;
	
hsyncOut <= hsync;
vsyncOut <= vsync;
xposOut <= xpos;
yposOut <= ypos;

END behavioral;

