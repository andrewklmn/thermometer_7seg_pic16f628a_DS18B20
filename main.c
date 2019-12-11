/*
 * File:   main.c
 * Author: andrewklmn
 * Created on 6 декабря 2019, 22:00
 */

#define _XTAL_FREQ 4000000      // тактовая частота
#define TEMP_DELTA 34


// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



#include <xc.h>
#include <pic16f628a.h>
#include "7-segment-x-3.h"
#include "onewire.h"


signed int temp = 1000;
int counter= 0;
int start_delay = 1;

void main(void) {
    
    
    //OSCCON = 0b01101100;
    
    //INTCON = 0b11000000;; //разрешить прерывания от периферии
    CMCON = 0b111; //Disable PORTA Comparators  
    // all of B is output
    TRISA = 0b00000001;
    TRISB = 0b00000000;
    LEDA = 0; 
    LEDB = 0;
    LEDC = 0;
    LEDD = 0;
    LEDE = 0;
    LEDF = 0;
    LEDG = 1;
    DOT = 0;
    LED1 = 1;
    LED2 = 0;
    LED3 = 1;
    
    //show_LED1(LETTER_EMPTY);
    //show_LED2(LETTER_MINUS);
    //show_LED3(LETTER_EMPTY);
    
    while(1){
        
        if (counter==0) { 
            init = init_ds() & 0b00000001;
            if (!init) {
                TX(0xCC);
                TX(0x44);
            }; 
        };
        
        if (nosensor==1) {
            show_LED1(LETTER_E);
            show_LED2(LETTER_E);
            show_LED3(LETTER_E);
        } else {
            if (temp==1000) {
                show_LED1(LETTER_EMPTY);
                show_LED2(LETTER_MINUS);
                show_LED3(LETTER_EMPTY);
            } else {
                if (start_delay==0) {
                    draw_to_LED(temp);
                } else {
                    show_LED1(LETTER_EMPTY);
                    show_LED2(LETTER_MINUS);
                    show_LED3(LETTER_EMPTY);
                };
            };
        };

        counter++;
        if (counter>100) {
            if (start_delay > 0) {
                start_delay--; 
                temp = get_temp(0)-TEMP_DELTA-15;
            } else {
                temp = get_temp(0)-TEMP_DELTA;
            };
            counter=0;
        };
        
        
    };
    return;
}