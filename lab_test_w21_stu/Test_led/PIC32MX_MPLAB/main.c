  
/* ***************************************************************************
 * File: main.c
 * Description: 
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author               Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Ezra-Fikru Asfaw     1/20/2022       Worked on Vtask1 & Vtask2.  ISN'T TASKA AND TASKB!
 *                            
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

QueueHandle_t xQueue;

/* Prototypes for the standard FreeRTOS callback/hook functions implemented within this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

int main( void )
{
    //Queue creation
    xQueue = xQueueCreate( 5, sizeof( int16_t ) );
    
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
    
    taskA();  BETTER NAME start_taskA
    taskB();
    
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

