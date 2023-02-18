/*
 * LCD.h
 *
 * Created: 5/12/2022 3:45:44 PM
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