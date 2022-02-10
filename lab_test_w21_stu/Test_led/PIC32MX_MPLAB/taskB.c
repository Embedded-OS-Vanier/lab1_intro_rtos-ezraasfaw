/* ***************************************************************************
 * File: taskB.c
 * Description: TaskB, when unblocked, must trickle all 5 letters one by one 
 * every 200mS or every 400mS
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
#include "taskA.h"

//QUEUE UNDECLARED
static QueueHandle_t xQueue1 = NULL;





static void vTaskB(){// TaskB

    
int cnt = 0;    
int y;
char buff[6];
 
while(1){
    
/* Receive data from the queue. The first parameter is the queue from which data is to be received. 
 * The second parameter is the buffer into which the received data will be placed. 
 * The last parameter is the block time */
    YOU DON'T NEED A SKIP COUNTER. JUST ADD A DELAY AFTER THE QUEUE UNBLOCKS
    if (cnt==5){
    cnt = 0;
    sprintf(buff, "   \n");
    fprintf2(C_UART1, buff);
    
   }
    else{
    // _LATA0 = 0;// Turns OFF a LED
    xQueueReceive( xQueue1,&y,portMAX_DELAY); 
   // _LATA0 = 1;// Turns ON a LED
    sprintf(buff, "%c ", y);
    fprintf2(C_UART1, buff);
    cnt++;
        }
}
    //vTaskDelay( 200 / portTICK_RATE_MS);
}

void vStartTaskB(void){
    xTaskCreate(vTaskB,"TI",240,NULL,2,NULL);
    }


void vInitQueue1(void){
    xQueue1 = xQueueCreate(5, sizeof(char));
}

void vSendQueue1(int data){
    xQueueSend(xQueue1,&data,0);
}
