#ifndef _ONEWIRE_H
#define _ONEWIRE_H

// Предполагается что датчики подключены на RA0-RA3


unsigned char nosensor;                 // флаг отсутствия сенсора
unsigned char init;

unsigned char init_ds(void);
void TX(unsigned char cmd);
unsigned char RX(void);
signed int get_temp(); //возвращает температуру на датчике номер ds 0-3

#endif