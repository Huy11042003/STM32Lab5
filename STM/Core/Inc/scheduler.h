/*
 * scheduler.h
 *
 *  Created on: Nov 22, 2023
 *      Author: Vostro
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <main.h>

#define SCH_MAX_TASKS	10
#define NO_TASK_ID		0

extern int global_time;

typedef struct {
	void (* pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

extern UART_HandleTypeDef huart2;
extern sTask SCH_tasks_G [SCH_MAX_TASKS];

void SCH_Init(void);
void SCH_Update(void);
uint32_t SCH_Add_Task(void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Task(void);
uint32_t SCH_Delete_Task(const uint32_t TASK_INDEX);
void update_time();
void timestamp(unsigned char index);

#endif /* INC_SCHEDULER_H_ */
