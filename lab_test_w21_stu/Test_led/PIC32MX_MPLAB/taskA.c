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
QUEUE UNDECLARED!

void TaskA(){
    
// TaskAlong 
    char cch;
    int num = 5;
    
    while(1){
        
   for (int i=0; i<num; i++){
           
        cch = 'A' + rand()%26;
        
        xQueueSendToBack(xQueue,&cch,0);
        fprintf2(C_UART1, "%c \n", cch);
        vTaskDelay( 4000 / portTICK_RATE_MS);
    
        }
   }
    
