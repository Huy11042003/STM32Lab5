/*
 * fsm_manual.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */

#include "manual.h"

void displayIncrease(int delay){
	switch(modeSeg){
		case FIRST:
			showTimeDelay1(delay);
			modeSeg = SECOND;
			break;
		case SECOND:
			showTimeDelay2(delay);
			modeSeg = FIRST;
			break;
		default:
			break;
	}
}
void displayIncreaseRed(){
	switch(modeSeg){
		case FIRST:
			showTimeDelay1(redDelay);
			modeSeg = SECOND;
			break;
		case SECOND:
			showTimeDelay2(redDelay);
			modeSeg = FIRST;
			break;
		default:
			break;
	}
}
void displayIncreaseYellow(){
	switch(modeSeg){
		case FIRST:
			showTimeDelay1(yellowDelay);
			modeSeg = SECOND;
			break;
		case SECOND:
			showTimeDelay2(yellowDelay);
			modeSeg = FIRST;
			break;
		default:
			break;
	}
}
void displayIncreaseGreen(){
	switch(modeSeg){
		case FIRST:
			showTimeDelay1(greenDelay);
			modeSeg = SECOND;
			break;
		case SECOND:
			showTimeDelay2(greenDelay);
			modeSeg = FIRST;
			break;
		default:
			break;
	}
}
int isDispatch = 0;
//void manual_run(){
//	switch(MODE){
		void MODE2(){
			HAL_GPIO_TogglePin( RED1_GPIO_Port , RED1_Pin) ;
			HAL_GPIO_TogglePin( RED2_GPIO_Port , RED2_Pin) ;
			if (isButtonPressed(1)==1){
				redDelay +=1;
				greenDelay +=1;

				if(redDelay >= 99) redDelay = 1;
			}
			if (isButtonPressed(2)==1){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
												  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
//				MODE = MODE1;
				setValues();
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(seg_fsm, 1, 50);
				SCH_Add_Task(RED_GREEN, 1, 100);

			}
			if (isButtonPressed(0) == 1){
//				MODE = MODE3;
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
										                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE3, 1, 50);
				SCH_Add_Task(displayIncreaseYellow, 1, 50);
			}
//
//			break;
		}
		void MODE3(){
////			if(timer_flag[3] == 1){
//				toggleLeds(YELLOW);
//				displayIncrease(yellowDelay);
////				setTimer(3, 25);
////			}

			HAL_GPIO_TogglePin( YELLOW1_GPIO_Port , YELLOW1_Pin) ;
			HAL_GPIO_TogglePin( YELLOW2_GPIO_Port , YELLOW2_Pin) ;
			if (isButtonPressed(1)==1){
				yellowDelay +=1;
				redDelay+=1;

				if(yellowDelay >= 99) yellowDelay = 1;
			}
			if (isButtonPressed(2)==1){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
												  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
//				MODE = MODE1;
				setValues();
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(seg_fsm, 1, 50);
				SCH_Add_Task(RED_GREEN, 1, 100);
			}
			if (isButtonPressed(0) == 1){
//				MODE = MODE4;
//				setTimer(3, 25);
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
										                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE4, 1, 50);
				SCH_Add_Task(displayIncreaseGreen, 1, 50);
			}
//			break;
		}
		void MODE4(){
////			if(timer_flag[3] == 1){
//				toggleLeds(GREEN);
//				displayIncrease(greenDelay);
////				setTimer(3, 25);
////			}

			HAL_GPIO_TogglePin( GREEN1_GPIO_Port , GREEN1_Pin) ;
			HAL_GPIO_TogglePin( GREEN2_GPIO_Port , GREEN2_Pin) ;
			if (isButtonPressed(1)==1){
				redDelay +=1;
				greenDelay +=1;

				if(greenDelay >= 99) greenDelay = 1;
			}
			if (isButtonPressed(2)==1){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
												  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
//				MODE = MODE1;
				setValues();
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(seg_fsm, 1, 50);
				SCH_Add_Task(RED_GREEN, 1, 100);
			}
			if (isButtonPressed(0) == 1){
//				MODE = MODE1;
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
										                          |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(seg_fsm, 1, 50);
				SCH_Add_Task(RED_GREEN, 1, 100);
			}
//			break;
//		default:
//			break;
	}
//}
