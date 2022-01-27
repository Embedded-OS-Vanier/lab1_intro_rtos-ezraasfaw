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



void vTaskB(){// TaskB
    
long y;

while(1){
    
/* Receive data from the queue. The first parameter is the queue from which data is to be received. 
 * The second parameter is the buffer into which the received data will be placed. 
 * The last parameter is the block time */
    _LATA0 = 0;// Turns OFF a LED
    
    xQueueReceive( xQueue,&y,portMAX_DELAY); 
   
    vTaskDelay( y / portTICK_RATE_MS);
}