#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <avr/io.h>

/* Use Watchdog Timer for system tick */
#define portUSE_WDTO                        WDTO_15MS

#define configUSE_PREEMPTION                1
#define configCPU_CLOCK_HZ                  ((uint32_t)F_CPU)
#define configTICK_RATE_HZ                  ((TickType_t)67)  /* ~15ms WDT period = ~66.67Hz */
#define configMAX_PRIORITIES                4
#define configMINIMAL_STACK_SIZE            85
#define configTOTAL_HEAP_SIZE               1024
#define configMAX_TASK_NAME_LEN             8
#define configUSE_16_BIT_TICKS              1
#define configIDLE_SHOULD_YIELD             1
#define configUSE_MUTEXES                   0
#define configUSE_RECURSIVE_MUTEXES         0
#define configUSE_COUNTING_SEMAPHORES       0
#define configUSE_QUEUE_SETS                0
#define configUSE_TIMERS                    0
#define configUSE_IDLE_HOOK                 0
#define configUSE_TICK_HOOK                 0
#define configUSE_MALLOC_FAILED_HOOK        0
#define configCHECK_FOR_STACK_OVERFLOW      0
#define configUSE_TRACE_FACILITY            0

#define INCLUDE_vTaskDelay                  1
#define INCLUDE_vTaskPrioritySet            0
#define INCLUDE_uxTaskPriorityGet           0
#define INCLUDE_vTaskDelete                 0
#define INCLUDE_vTaskSuspend                0
#define INCLUDE_xTaskDelayUntil             0
#define INCLUDE_xTaskGetSchedulerState      0

#endif
