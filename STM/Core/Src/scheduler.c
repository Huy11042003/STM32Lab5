/*
 * scheduler.c
 *
 *  Created on: Nov 22, 2023
 *      Author: Vostro
 */

#include "scheduler.h"
#include "main.h"

int global_time=0;

sTask SCH_tasks_G [SCH_MAX_TASKS];
void SCH_Init(void) {
	unsigned char i;
	for (i=0;i<SCH_MAX_TASKS;i++) {
		SCH_tasks_G[i].pTask = 0x0000;
		SCH_tasks_G[i].Delay = 0;
		SCH_tasks_G[i].Period = 0;
		SCH_tasks_G[i].RunMe = 0;
		SCH_tasks_G[i].TaskID = -1;
	}
}

void SCH_Update(void) {
	unsigned char index;
	for (index=0;index<SCH_MAX_TASKS;index++) {
		 if (SCH_tasks_G[index].pTask && SCH_tasks_G[index].Delay == 0) {
			SCH_tasks_G[index].RunMe += 1;
			if (SCH_tasks_G[index].Period) {
				SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period-1;
			}
		} else if (SCH_tasks_G[index].pTask && SCH_tasks_G[index].Delay>0) {
			SCH_tasks_G[index].Delay -= 1;
		}
	}
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	unsigned char index=0;
	while ((SCH_tasks_G[index].pTask != 0x0000) && (index < SCH_MAX_TASKS)) {
		index++;
	}
	if (index>=SCH_MAX_TASKS) {
		return -1;
	}
	SCH_tasks_G [ index ].pTask = pFunction;
	SCH_tasks_G [ index ].Delay = (DELAY == 0)?0:DELAY-1;
	SCH_tasks_G [ index ].Period = PERIOD ;
	SCH_tasks_G [ index ].RunMe = 0 ;
	SCH_tasks_G [ index ].TaskID = index;
	return index;
}

void SCH_Dispatch_Task(void) {
	unsigned char index;
	for (index=0;index<SCH_MAX_TASKS;index++) {
		if (SCH_tasks_G[index].RunMe>0) {
			(*SCH_tasks_G[index].pTask)();
			SCH_tasks_G[index].RunMe -= 1;
			if (SCH_tasks_G[index].Period == 0 && SCH_tasks_G[index].RunMe == 0 && SCH_tasks_G[index].Delay==0) {
				SCH_Delete_Task(index);
			}
			timestamp(index);
		}
	}
}

uint32_t SCH_Delete_Task(uint32_t TASK_INDEX) {
	if (TASK_INDEX < 0 || TASK_INDEX >= SCH_MAX_TASKS) {
		return -1;
	}
	if (SCH_tasks_G[TASK_INDEX].pTask==0x0000) {
		return -1;
	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period = 0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	SCH_tasks_G[TASK_INDEX].TaskID = -1;
	return TASK_INDEX;
}

void update_time() {
	global_time+=10;
}

void timestamp(unsigned char index) {
	char str[30];
	HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "TaskID: %d", index), 1000);
	HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, " timeout at %d\r", global_time), 1000);
}
