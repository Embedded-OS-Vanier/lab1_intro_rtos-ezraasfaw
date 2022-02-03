  
/* ***************************************************************************
 * File: main.c
 * Description: 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author               Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Ezra-Fikru Asfaw     1/20/2022       Worked and completed  Vtask1 & Vtask2. 
 * Ezra-Fikru Asfaw     1/27/2022       Worked on VtaskA & VtaskB.  
 * Ezra-Fikru Asfaw     2/3/2022        Completed VtaskA & VtaskB. LCD doesn't work.                         
 *****************************************************************************/

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h" 
#include "semphr.h"
#include "croutine.h"
/* Hardware specific includes. */
#include "include/ConfigPerformance.h"
#include "include/console32.h"
#include "include/public.h"
#include "taskA.h"
#include "taskB.h"

QueueHandle_t xQueue;

/* Prototypes for the standard FreeRTOS callback/hook functions implemented within this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

int main( void )
{
    //Queue creation
   // xQueue = xQueueCreate( 5, sizeof( int16_t ) );
    
    /* Prepares the hardware */
	prvSetupHardware();
    //initIO();
    //LCDInit();
    initUart1();
    //initUart2_wInt();
    
    fprintf2(C_UART1, "Hi Uart1\n");
    
    /* create tasks here */
    //vStartTask1();
    //vStartTask2();
    
    vInitQueue1();
    
    vStartTaskA();
    vStartTaskB();
    
    vTaskStartScheduler();
	return 0;
}
/*-----------------------------------------------------------*/


void vApplicationIdleHook( void ){
    while(1){
        //your code here
    }
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    pxTask= pxTask;
    pcTaskName = pcTaskName;
		for( ;; );
}

