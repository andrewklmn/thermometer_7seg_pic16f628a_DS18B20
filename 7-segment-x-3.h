/* 
 * File:   7-segment-x-3.h
 * Author: user
 *
 * Created on 6 березня 2017, 23:57
 */

#ifndef _7_SEGMENT_X_3_H_
#define	_7_SEGMENT_X_3_H_

#define _XTAL_FREQ 4000000    // частота генератора - ПОПРАВИТЬ!!!

#define SYMBOL_DISPLAY_TIME_MS 6

#define LEDA RB0    // LED segments
#define LEDB RB1
#define LEDC RB2
#define LEDD RB3
#define LEDE RB4
#define LEDF RB5
#define LEDG RB6
#define DOT RB7


#define LED1 RA4    //LED position
#define LED2 RA6
#define LED3 RA7
\
#define LETTER_A 10
#define LETTER_d 11
#define LETTER_grad 12
#define LETTER_h 13
#define LETTER_o 14
#define LETTER_t 15
#define LETTER_EMPTY 16
#define LETTER_MINUS 17
#define LETTER_E 18 


void convert_to_segment(char);
void show_LED1(char);
void show_LED2(char);
void show_LED3(char);
void draw_to_LED(int);
void draw_add(void);
void draw_minus(void);
void draw_temp(char);
void draw_needed_amount(char);
void init_LED(void);
void draw_empty(void);
void draw_to(void);
void draw_hot(void);
#endif	/* 7_SEGMENT_X_3_H */
