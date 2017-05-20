#ifndef _HAL_H_
#define _HAL_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

//@ #include "ghost-chibios.gh"

#define GPIOA 0x00000100
#define GPIOB 0x00000200
#define GPIOC 0x00000300
#define GPIOA_LED_GREEN 5U
#define GPIOC_BUTTON    13U

struct BaseBlockDevice_struct {
  void *dummy;
};
typedef struct BaseBlockDevice_struct BaseBlockDevice;

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

void halInit(void);
    //@ requires chibios_sys_state_context(currentThread, InitState);
    //@ ensures chibios_sys_state_context(currentThread, HALInitedState);

uint8_t palReadPad(int port, uint32_t pad);
    //@ requires true;
    //@ ensures true;

void palSetPad(int port, uint32_t pad);
    //@ requires true;
    //@ ensures true;

void palClearPad(int port, uint32_t pad);
    //@ requires true;
    //@ ensures true;

bool blkIsInserted(BaseBlockDevice *bbdp);
    //@ requires true;
    //@ ensures true;

#endif /* _HAL_H_ */
