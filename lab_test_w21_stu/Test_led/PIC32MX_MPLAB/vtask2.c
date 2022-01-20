
/* ***************************************************************************
 * File: vTask2.c
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

#define DELAY_LOOP_COUNT 150000


int ul=0;

/* Private static function declarations */
static void vTask2( void *pvParameters )
{

   pvParameters = pvParameters ;    // This is to get rid of annoying warnings
   //while(1);
   	while( 1 )
	{   
        for( ul= 0; ul< DELAY_LOOP_COUNT; ul++ );
        fprintf2(C_UART1,"Task 2\n"); //message print on UART 1 Output
    }
   
}



/* Public function declarations */
void vStartTask2(void){
      xTaskCreate( vTask2, ( char * ) "Task 2", 240, NULL, 1, NULL ); //Crude null loop delay for a period.
      /* Crude null loop delay for a period. */
      
}






