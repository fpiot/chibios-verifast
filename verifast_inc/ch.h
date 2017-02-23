#ifndef _CH_H_
#define _CH_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

//@ #include "ghost-chibios.gh"

struct ch_thread {
  void *dummy;
};
typedef struct ch_thread thread_t;

struct ch_virtual_timer {
  void *dummy;
};
typedef struct ch_virtual_timer virtual_timer_t;

struct event_source {
  void *dummy;
};
typedef struct event_source event_source_t;

typedef uint32_t tprio_t;
typedef void *tfunc_t;

#define THD_FUNCTION(tname, arg) void tname(void *arg)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

void chSysInit(void);
    //@ requires chibios_sys_state_context(currentThread, HALInitedState);
    //@ ensures chibios_sys_state_context(currentThread, ThreadState);

void chThdSleepMilliseconds(uint32_t msec);
    //@ requires chibios_sys_state_context(currentThread, ThreadState);
    //@ ensures chibios_sys_state_context(currentThread, ThreadState);

thread_t *chThdCreateStatic(void *wsp, size_t size,
                            tprio_t prio, tfunc_t pf, void *arg);

struct SerialDriver;
typedef struct SerialDriver SerialDriver;
struct SerialConfig;
typedef struct SerialConfig SerialConfig;
SerialDriver SD2;

void sdStart(SerialDriver *sdp, const SerialConfig *config);
    //@ requires chibios_sys_state_context(currentThread, ThreadState);
    //@ ensures chibios_sys_state_context(currentThread, ThreadState);

#endif /* _CH_H_ */
