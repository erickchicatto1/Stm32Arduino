#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include <Arduino.h>  // Incluye Arduino.h para usar Serial

int addTwoInts(int a, int b);


#ifdef __cplusplus
extern "C" {
#endif

void inicializar_driver();

#ifdef __cplusplus
}
#endif


#endif