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


#define UART1_DELAY_TASKB 20
#define UART2_DELAY_TASKB 200

//QUEUE UNDECLARED
static QueueHandle_t xQueue1 = NULL;





static void vTaskB(){// TaskB

    
int cnt = 0;    
int rx;
char buff[6];

while(1){
    
/* Receive data from the queue. The first parameter is the queue from which data is to be received. 
 * The second parameter is the buffer into which the received data will be placed. 
 * The last parameter is the block time */

    xQueueReceive( xQueue1,&rx,portMAX_DELAY);
    vTaskDelay( getSpeed() / portTICK_RATE_MS);
    sprintf(buff, "%c ", rx);
    fprintf2(C_UART2, buff);

    }
  
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
