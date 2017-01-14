#ifndef _CH_H_
#define _CH_H_

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct ch_thread {
  void *dummy;
};
typedef struct ch_thread thread_t;
typedef uint32_t tprio_t;
typedef void *tfunc_t;

#define THD_FUNCTION(tname, arg) void tname(void *arg)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

void chSysInit(void);
    //@ requires true;
    //@ ensures true;

void chThdSleepMilliseconds(uint32_t msec);
    //@ requires true;
    //@ ensures true;

thread_t *chThdCreateStatic(void *wsp, size_t size,
                            tprio_t prio, tfunc_t pf, void *arg);

struct SerialDriver;
typedef struct SerialDriver SerialDriver;
struct SerialConfig;
typedef struct SerialConfig SerialConfig;
SerialDriver SD2;

void sdStart(SerialDriver *sdp, const SerialConfig *config);
    //@ requires true;
    //@ ensures true;

#endif /* _CH_H_ */
