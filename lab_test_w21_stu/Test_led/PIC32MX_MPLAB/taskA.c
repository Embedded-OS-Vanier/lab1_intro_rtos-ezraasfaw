/* ***************************************************************************
 * File: taskA.c
 * Description: taskA must unblock taskB every four seconds using a queue. 
 * taskA fills a transmitting queue with a burst of 5 random capital letters 
 * every four seconds.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                                  - v1
 *****************************************************************************/

#include <string.h>
#include <stdio.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "include/public.h"
#include "include/console32.h"


#define UART1_DELAY_TASKA 120
#define UART2_DELAY_TASKA 4000

static QueueHandle_t xQueueA = NULL;

static void vTaskA(void *pvParameters){
    
    char buff;
    int cch;
    int num = 5;
    int i;
    
    while(1){

    for(i=0; i<num; i++){
        cch = 'A' + rand()%26;
        vSendQueue1(cch);
        
        }
        vTaskDelay( UART2_DELAY_TASKA / portTICK_RATE_MS); 
        fprintf2(C_UART2, "\n\r");
    }
}

void vStartTaskA(void){
    xTaskCreate(vTaskA,"TI",240,NULL,1,NULL);
}
