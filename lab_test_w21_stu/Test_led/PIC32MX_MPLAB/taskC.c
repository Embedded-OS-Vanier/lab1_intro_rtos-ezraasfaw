/* ***************************************************************************
 * File: taskC.c
 * Description: TaskC changes the period to 200mS whenever PB1 is 
 * pressed-released and change it to 400mS whenever PB2 is pressed-released.
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
#include "include/initBoard.h"
#include "include/public.h"
#include "include/console32.h"

#define BTN1WAIT 10
#define BTN2WAIT 2000

#define BTN1SPEED 20
#define BTN2SPEED 400

#define MAX_SPEED 1000

#define BTN1 PORTDbits.RD6
#define BTN2 PORTDbits.RD7

/* Private static data declarations */
static unsigned int speed=0;
/* Private static mutex, semaphore and queue declarations*/
static SemaphoreHandle_t mutexSpeed;
static QueueHandle_t xQueueCtl = NULL;
/* Private static function declarations */
static void vTaskC( void *pvParameters );





static void vTaskC( void *pvParameters ){
    
    vInitTaskC();

    for( ;; ){
        vTaskDelay( BTN1WAIT / portTICK_RATE_MS );
        if(BTN1 == 0){
            setSpeed(BTN1SPEED);
        }
        //vTaskDelay( BTN2WAIT / portTICK_RATE_MS );
        if(BTN2 == 0){
            setSpeed(BTN2SPEED);
        }
    }
}










void setSpeed(int _speed){

xSemaphoreTake( mutexSpeed, portMAX_DELAY );
speed = _speed;
xSemaphoreGive( mutexSpeed);

}
int getSpeed(void){
int _speed;
xSemaphoreTake( mutexSpeed, portMAX_DELAY );
_speed = speed;
xSemaphoreGive( mutexSpeed);
return _speed;
}











void vStartTaskC(void){
    xTaskCreate(vTaskC,"TI",240,NULL,3,NULL);
}    

void vInitTaskC(void){
    mutexSpeed = xSemaphoreCreateMutex();
}

