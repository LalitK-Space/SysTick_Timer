# SysTick_Timer
 Configuring SysTick Timer for ARM Cortex Mx Processors

## WHY?
Creating these configuration files is intended to provide ready-to-use SysTick Timer code for future applications.

SysTick Timer is a fairly common method to have an exception at a desired clock cycle or time interval. The init_SysTick_Timer function implemented takes an argument in milliseconds to generate the exception at a provided time interval. 