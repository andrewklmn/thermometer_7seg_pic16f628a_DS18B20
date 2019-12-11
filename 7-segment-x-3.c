#include <xc.h>
#include "7-segment-x-3.h"

void convert_to_segment( char value ){
    switch(value){
        case LETTER_EMPTY:  //пустое значение
            LEDA = 0; 
            LEDB = 0;
            LEDC = 0;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 0;
            break;
        case LETTER_MINUS:    //символ минуса
            LEDA = 0; 
            LEDB = 0;
            LEDC = 0;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 1;
            break;
        case 0:
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 0;
            break;
        case 1:    
            LEDA = 0; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 0;
            break;
        case 2:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 0;
            LEDD = 1;
            LEDE = 1;
            LEDF = 0;
            LEDG = 1;
            break;
        case 3:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 0;
            LEDF = 0;
            LEDG = 1;
            break;
        case 4:    
            LEDA = 0; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 0;
            LEDE = 0;
            LEDF = 1;
            LEDG = 1;
            break;
        case 5:    
            LEDA = 1; 
            LEDB = 0;
            LEDC = 1;
            LEDD = 1;
            LEDE = 0;
            LEDF = 1;
            LEDG = 1;
            break;
        case 6:    
            LEDA = 1; 
            LEDB = 0;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
        case 7:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 0;
            LEDE = 0;
            LEDF = 0;
            LEDG = 0;
            break;
        case 8:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
        case 9:    
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 0;
            LEDF = 1;
            LEDG = 1;
            break;
        case LETTER_A:        // symbol 'A'
            LEDA = 1; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 0;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
        case LETTER_d:        // symbol 'd'
            LEDA = 0; 
            LEDB = 1;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 0;
            LEDG = 1;
            break;
        case LETTER_grad:        // symbol 'grad'
            LEDA = 1; 
            LEDB = 1;
            LEDC = 0;
            LEDD = 0;
            LEDE = 0;
            LEDF = 1;
            LEDG = 1;
            break;
        case LETTER_h:        // symbol 'h'
            LEDA = 0; 
            LEDB = 0;
            LEDC = 1;
            LEDD = 0;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
        case LETTER_o:        // symbol 'o'
            LEDA = 0; 
            LEDB = 0;
            LEDC = 1;
            LEDD = 1;
            LEDE = 1;
            LEDF = 0;
            LEDG = 1;
            break;
        case LETTER_t:        // symbol 't'
            LEDA = 0; 
            LEDB = 0;
            LEDC = 0;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
        default:        // symbol - 'E'
            LEDA = 1; 
            LEDB = 0;
            LEDC = 0;
            LEDD = 1;
            LEDE = 1;
            LEDF = 1;
            LEDG = 1;
            break;
    };
};

void show_LED1(char c){
    convert_to_segment(c);
    LED1 = 0;
    __delay_ms(SYMBOL_DISPLAY_TIME_MS);
    LED1 = 1;
};

void show_LED2(char c){
    convert_to_segment(c);
    LED2 = 0;
    __delay_ms(SYMBOL_DISPLAY_TIME_MS);
    LED2 = 1;
};

void show_LED3(char c){
    convert_to_segment(c);
    LED3 = 0;
    __delay_ms(SYMBOL_DISPLAY_TIME_MS);
    LED3 = 1;
};

void draw_add() {
    show_LED1(LETTER_A);
    show_LED2(LETTER_d);
    show_LED3(LETTER_d);
};

void draw_temp(char i){
    char d = i/10;
    //convert_to_segment(d);
    if ( d > 0 ) {
        show_LED1(d);
    } else {
        show_LED1(LETTER_EMPTY);
    };
    d = i - i/10*10;
    show_LED2(d);
    show_LED3(LETTER_grad);
};

void draw_needed_amount(char i){
    show_LED1(LETTER_EMPTY);
    show_LED2(i);
    show_LED3(LETTER_EMPTY);    
};

void draw_minus(){
    show_LED1(LETTER_EMPTY);
    show_LED2(LETTER_MINUS);
    show_LED3(LETTER_EMPTY);
};

void draw_to(){
    show_LED1(LETTER_t);
    show_LED2(LETTER_o);
    show_LED3(LETTER_o);    
};

void draw_hot(){
    show_LED1(LETTER_h);
    show_LED2(LETTER_o);
    show_LED3(LETTER_t);
};


void draw_to_LED(int i){
    signed int d;
    if (i>=0) {
    
        int d = i/100;
        if (d>0) {
            show_LED1(d);
        } else {
            show_LED1(LETTER_EMPTY);
        };
        d = i/10 - i/100*10;
        DOT = 1;
        show_LED2(d);
        DOT = 0;
        
        d = i - i/10*10;
        show_LED3(d);
        
    } else {
        
        d = -i/100;
        if (d>0) {
            show_LED1(LETTER_MINUS);
            show_LED2(d);
            d = -i/10 + i/100*10;
            show_LED3(d);
        } else {
            show_LED1(LETTER_MINUS);
            d = -i/10 + i/100*10;
            DOT = 1;
            show_LED2(d);
            DOT = 0;
            
            d = -i + i/10*10;
            show_LED3(d);
        };
        LED1 = 1; // выключаем все знаки
        LED2 = 1;
        LED3 = 1;
    };
    LEDA = 0; // засвечиваем все сегменты на старте
    LEDB = 0;
    LEDC = 0;
    LEDD = 0;
    LEDE = 0;
    LEDF = 0;
    LEDG = 0;
    DOT  = 0;
};


void init_LED(){
    LEDA = 1; // засвечиваем все сегменты на старте
    LEDB = 1;
    LEDC = 1;
    LEDD = 1;
    LEDE = 1;
    LEDF = 1;
    LEDG = 1;
    
    LED1 = 0; // включаем все знаки
    LED2 = 0;
    LED3 = 0;
    
    __delay_ms(500);
    
    LED1 = 1; // выключаем все знаки
    LED2 = 1;
    LED3 = 1;
};

void draw_empty(){
    LEDA = 0; // засвечиваем все сегменты на старте
    LEDB = 0;
    LEDC = 0;
    LEDD = 0;
    LEDE = 0;
    LEDF = 0;
    LEDG = 0;
    
    LED1 = 0; // включаем все знаки
    LED2 = 0;
    LED3 = 0;
    
    __delay_ms(SYMBOL_DISPLAY_TIME_MS);
    
    LED1 = 1; // выключаем все знаки
    LED2 = 1;
    LED3 = 1;
};