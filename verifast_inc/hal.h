#ifndef _HAL_H_
#define _HAL_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define GPIOC 0x00000800
#define GPIOC_BUTTON 13

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

void halInit(void);
    //@ requires true;
    //@ ensures true;

uint8_t palReadPad(int i, uint32_t p);
    //@ requires true;
    //@ ensures true;

#endif /* _HAL_H_ */
