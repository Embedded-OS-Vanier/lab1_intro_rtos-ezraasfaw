/* 
 * File:   taskB.h
 * Author: Ezra-Fikru Asfaw
 *
 * Created on January 27, 2022, 11:46 AM
 */

#ifndef TASKB_H
#define	TASKB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
void TaskB();
void vStartTaskB();
void vInitQueue1(void);
void vSendQueue1(int data);

#ifdef	__cplusplus
}
#endif

#endif	/* TASKB_H */

