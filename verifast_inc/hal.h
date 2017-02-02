#ifndef _HAL_H_
#define _HAL_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

//@ #include "ghost-chibios.gh"

#define GPIOC 0x00000800
#define GPIOC_BUTTON 13

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

void halInit(void);
    //@ requires chibios_sys_state_context(currentThread, 0);
    //@ ensures true;

uint8_t palReadPad(int i, uint32_t p);
    //@ requires true;
    //@ ensures true;

#endif /* _HAL_H_ */
