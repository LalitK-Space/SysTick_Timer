/*
 * systick_timer.h
 *      
 */

#ifndef SYSTICK_TIMER_H_
#define SYSTICK_TIMER_H_

#include <stdint.h>

/* -- SysTick Timer Registers --  */
#define SYST_RVR		(volatile uint32_t *) 0xE000E014	// SysTick Reload Value Register
#define SYST_CSR		(volatile uint32_t *) 0xE000E010	// SysTick Control and Status Register

/* -- Clock Source for SysTick Timer -- */
#define SYSTICK_TIMER_CLOCK		16000000U				        // SysTick CLock Source (set to 16MHz)


/* -- API to configure the SysTick Timer to generate a desired exception time interval --  */
void init_SysTick_Timer(uint32_t desiredException_ms);


#endif /* SYSTICK_TIMER_H_ */
