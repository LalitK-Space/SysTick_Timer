/*
 * 
 * systick_timer.c
 * 
 * init_SysTick_Timer generates a SysTick Exception at the desired time in milliseconds
 *    
 */

#include "systick_timer.h"

#include <stdio.h>
#include <stdlib.h>

/* ------------------------------------------------------------------------------------------------------
 * Name		:	init_SysTick_Timer
 * Description	:	Initialize the SysTick Timer
 * Parameter 1	:	desiredException_ms (Exception Frequency at every provided millisecond)
 * Return Type	:	none (void)
 * Note		:	
 * ------------------------------------------------------------------------------------------------------ */


void init_SysTick_Timer(uint32_t desiredException_ms)
{
	/* -- STEP 1: Calculating Reload Value for SysTick Reload Value Register -- */
	uint32_t reloadValue;

	/* -- Calculating the Reload value w.r.t milliseconds-- */
	reloadValue = ((SYSTICK_TIMER_CLOCK / 1000) * desiredException_ms) - 1;


	/* -- STEP 2: Loading the Reload Value into SVR -- */
	*SYST_RVR &= ~(0x00FFFFFFFF);	// Clearing Reload Value Register
	*SYST_RVR |= reloadValue;		// Loading calculated Reload Value


	/* -- STEP 3: Configuring SysTick Control and Status Register -- */
	/* 
	  Bit[1]:	TICKINT: Enables SysTick Exception
	  					 0 = Counting down to zero does not assert the SysTick Exception
						 1 = Counting down to zero assert the SysTick Exception 

	  Bit[2]:	CLKSOURCE: Indicate the Clock Source
	  						0 = External Clock
							1 = Processor Clock	 

	  Bit[0]:	ENABLE:	Enables the Counter
	  					0 = Counter Disabled
						1 = Counter Enabled												  	
	*/

	*SYST_CSR |= (1 << 1);		// Configuring TICKINT bit of SYST_CSR as Counting down to zero assert the SysTick Exception 	
	*SYST_CSR |= (1 << 2);		// Configuring CLKSOURCE bit of SYST_CSR to use Processor Clock for SysTick Clock source

	*SYST_CSR |= (1 << 0);		// Configuring ENABLE bit to enable the SysTick Timer 

}





