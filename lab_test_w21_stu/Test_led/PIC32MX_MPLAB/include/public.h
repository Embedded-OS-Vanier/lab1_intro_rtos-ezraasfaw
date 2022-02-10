/* ***************************************************************************
 * File: public.h
 * Description: contains public prototypes and shared macros
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                                  - v1
 *****************************************************************************/

#ifndef PUBLIC_H
#define PUBLIC_H


//#define     CONSOLE     C_LCD
#define     CONSOLE     C_UART1

static void vTaskA(void *pvParameters);
void vStartTask1(void);
void vStartTask2(void);
void TaskB();
void vStartTaskB();
void vInitQueue1(void);
void vSendQueue1(int data);
static void vTaskC( void *pvParameters );
void vStartTaskC(void);
void setSpeed(int _speed);
int getSpeed(void);
void vStartTaskC(void);
void vInitTaskC(void);

#endif /* PUBLIC_H */


