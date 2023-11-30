/*
 * fsm_auto.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */
#include "auto.h"

		void RED_GREEN(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
			}
			displayFirstLedCouple(RED);
			displaySecondLedCouple(GREEN);
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownSecondCoupleLed == 0){
					countdownSecondCoupleLed = yellowDelay;
					SCH_Delete_Task(1);
					SCH_Add_Task(RED_YELLOW, 1, 100);
				}
			}
		void RED_YELLOW(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
			}
			displayFirstLedCouple(RED);
			displaySecondLedCouple(YELLOW);
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownSecondCoupleLed == 0){
					countdownSecondCoupleLed = redDelay;
					countdownFirstCoupleLed = greenDelay;
					SCH_Delete_Task(1);
					SCH_Add_Task(GREEN_RED, 1, 100);
				}
			}
		void GREEN_RED(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
			}
			displayFirstLedCouple(GREEN);
			displaySecondLedCouple(RED);
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownFirstCoupleLed == 0){
					countdownFirstCoupleLed = yellowDelay;
					SCH_Delete_Task(1);
					SCH_Add_Task(YELLOW_RED, 1, 100);
				}
			}
		void YELLOW_RED(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
			}
			displayFirstLedCouple(YELLOW);
			displaySecondLedCouple(RED);
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownFirstCoupleLed == 0){
					countdownSecondCoupleLed = greenDelay;
					countdownFirstCoupleLed = redDelay;
					SCH_Delete_Task(1);
					SCH_Add_Task(RED_GREEN, 1, 100);
				}
			}
void seg_fsm(){
	switch(seg7AutoState){
		case FIRST:
			showTimeDelay_First(countdownFirstCoupleLed, countdownSecondCoupleLed);
			seg7AutoState = SECOND;
			break;
		case SECOND:
			showTimeDelay_Second(countdownFirstCoupleLed, countdownSecondCoupleLed);
			seg7AutoState = FIRST;
			break;
		default:
			break;
	}
}
