
/* ***************************************************************************
 * File: vTask1.c
 * Description: to complete
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

/* Private static function declarations */
static void vTask1( void *pvParameters )
{
    pvParameters = pvParameters ; // This is to get rid of annoying warnings
	/* As per most tasks, this task is implemented in an infinite loop. */

	while(1)
	{   
        vTaskDelay(30/portTICK_RATE_MS); //Delay for a 30 mS period.
        fprintf2(C_UART1,"Task 1\n"); //Message print on UART 1 Output
    }
}

/* Public function declarations */
void vStartTask1(void){
     xTaskCreate(	vTask1,						/* Pointer to the function that implements the task. */
					( char * ) "Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
					240,						/* Stack depth in words. */
					NULL,						/* We are not using the task parameter. */
					2,							/* This task will run at priority 1. */
					NULL );						/* We are not using the task handle. */

}
