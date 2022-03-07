#ifndef D_LedDriver_H
#define D_LedDriver_H
#include <stdint.h>   // uint16_t

/**********************************************************
 *
 * LedDriver is responsible for ...
 *
 **********************************************************/

void LedDriver_Create(uint16_t* address);
void LedDriver_Destroy(void);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);

#endif  /* D_FakeLedDriver_H */
