#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"

void vBlinkTask(void *pvParameters) {
    (void)pvParameters;
    DDRB |= (1 << PB7);
    
    for (;;) {
        PORTB ^= (1 << PB7);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

int main(void) {
    xTaskCreate(vBlinkTask, "Blink", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    vTaskStartScheduler();
    for (;;);
}
