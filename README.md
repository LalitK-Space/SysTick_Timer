# SysTick_Timer
 Configuring SysTick Timer for ARM Cortex Mx Processors

## WHY?
Creating these configuration files is intended to provide ready-to-use SysTick Timer code for future applications.

SysTick Timer is a fairly common method to have an exception at a desired clock cycle or time interval. The init_SysTick_Timer function implemented takes an argument in milliseconds to generate the exception at a provided time interval. 

## Analyzing the accuracy
>The code is tested to generate time intervals, and exception frequency is analyzed using a Logic Analyzer.

Initializing SysTick Timer to generate exceptions every 100 milliseconds.<br>
A GPIO is toggled at every SysTick Exception.
</br>

`Analyzer Screenshot`
![analyzer](SysTick_Timer\Others\analyzer.png)

The desired time interval between toggling was 100ms, as set in the init_SysTick_Timer, and we got 99.832ms.

