/*
 * LCD.h
 *
 * Created: 5/24/2022 2:35:28 PM
 *  Author: chris
 */ 


#ifndef LCD_H_
#define LCD_H_
void LCD_Init(void);
void LCD_command (char cmnd);
void LCD_char(char char_data);
void LCD_string (char str[]);
void LCD_clear();
#endif /* LCD_H_ */
