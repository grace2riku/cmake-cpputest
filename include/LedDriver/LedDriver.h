#ifndef D_LedDriver_H
#define D_LedDriver_H
#include <stdint.h>   // uint16_t

#define TRUE 1
#define FALSE 0
typedef int BOOL;

/**********************************************************
 *
 * LedDriver is responsible for ...
 *
 **********************************************************/

void LedDriver_Create(uint16_t* address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);

#endif  /* D_FakeLedDriver_H */
