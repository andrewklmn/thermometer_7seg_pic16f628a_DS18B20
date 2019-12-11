#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "onewire.h"
#define _XTAL_FREQ 4000000    


// Обслуживает  DS18B20 на RA0

unsigned char init_ds(){
    unsigned char b;
    unsigned char control0 = 0b11111110;
    // пробуем сразу все четыре датчика
    TRISA &= control0; // переключили на выход RA0-RA03
    PORTA &= control0; // просадили на 500 мс
    __delay_us(500);
    TRISA |= ~control0;
    __delay_us(65);
    b = PORTA;
    __delay_us(450);
    return b;
}

void TX(unsigned char cmd){     // передача комманды сразу на все выводы с датчиками
    unsigned char temp = 0;
    unsigned char i = 0;
    unsigned char control0 = 0b11111110;
    temp = cmd;
    for (i=0;i<8;i++) {
        if (temp&0x01) {
            TRISA &= control0; // переключили на выход только нужный RA0-RA03
            PORTA &= control0; // опустили в ноль только нужный вход
            __delay_us(5);
            TRISA |= ~control0; // переключаем опять на вход нужный бит
            __delay_us(70);
        } else {
            TRISA &= control0; // переключили на выход RA0-RA03
            PORTA &= control0;
            __delay_us(70);
            TRISA |= ~control0;
            __delay_us(5);

        }
        temp >>= 1;
    }
}

unsigned char RX() { // считывание по указаному биту RA0-RA3 соотв 0-3
    unsigned char d = 0;    // результат считывания битов
    unsigned char i = 0;    // счётчик для битов 
    for (i=0;i<8;i++){
        TRISA0 = 0; // переключили на выход RA0
        RA0 = 0;
        __delay_us(5);
        TRISA0 = 1; // 
        __delay_us(4);
        d>>=1;// сдвигаем прошлый бит вправо на 1
        if (RA0 == 1) d |= 0x80;   // если на входе 1, то высталяем бит на 1 
        __delay_us(60);	
    };
    return d;
}

signed int get_temp() {
    
    unsigned char temp1 = 0;
    unsigned char temp2 = 0;
    unsigned char temp_drob;
    signed int temperature;           // температура х10 в цельсиях
    unsigned char signloc;            // знак температуры

    /*
    init = init_ds() & 0b00000001;
    if (!init) {
        TX(0xCC);
        TX(0x44);
        __delay_ms(150);
        __delay_ms(150);
        __delay_ms(150);
        __delay_ms(150);
        __delay_ms(150); 
    };
    */
    init = init_ds() & 0b00000001;
    if (!init) {
        
        TX(0xCC);       // считываем температуру
        TX(0xBE);
        temp1 = RX();
        temp2 = RX();
            
        signloc = (temp2 & 0x80) >> 7;  // определяем знак температуры
        temp_drob = temp1 & 0b00001111; // дробная часть температуры
        
        temp1 >>= 4;                    // отбрасываем дробную часть температуры
        temp2 <<= 4;                    // сдвигаем старший бит температуры влево
        temp2 &= 0b01110000;            // обнуляем знаковый бит и 4 младших бита
        temp2 |= temp1;                 // получаем целую часть температуры
        nosensor = 0;
        // возвращаем температуру в виде int умноженнуж на 10
        if (signloc == 1) {             // если отрицательная температура то так
            return temperature = -((127-temp2)*10 + (10 - temp_drob*10/16));
        };
        return temperature = temp2*10 + temp_drob*10/16;    // если положительная то так        
    } else {
        nosensor = 1; // поднимаем флаг что датчик отключен
        return 0;     // возращаем нулевую температуру
    };
}