#ifndef _TEST_H_
#define _TEST_H_

//@ #include "ghost-chibios.gh"

void TestThread(void *p);
    //@ requires chibios_sys_state_context(currentThread, ThreadState);
    //@ ensures chibios_sys_state_context(currentThread, ThreadState);

#endif /* _TEST_H_ */
