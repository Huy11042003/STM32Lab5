/*
 * fsm_auto.c
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */
#include "auto.h"

//void led_fsm(){
//	switch(autostate){
		void RED_GREEN(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
//				MODE = MODE2;
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
//				break;
			}
			displayFirstLedCouple(RED);
			displaySecondLedCouple(GREEN);
//			if(timer_flag[0] == 1){
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownSecondCoupleLed == 0){
					countdownSecondCoupleLed = yellowDelay;
//					autostate = RED_YELLOW;
					SCH_Delete_Task(1);
					SCH_Add_Task(RED_YELLOW, 1, 100);
				}
//				setTimer(0, 100);
			}
//			break;
		void RED_YELLOW(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
//				MODE = MODE2;
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
//				break;
			}
			displayFirstLedCouple(RED);
			displaySecondLedCouple(YELLOW);
//			if(timer_flag[0] == 1){
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownSecondCoupleLed == 0){
					countdownSecondCoupleLed = redDelay;
					countdownFirstCoupleLed = greenDelay;
//					autostate = GREEN_RED;
					SCH_Delete_Task(1);
					SCH_Add_Task(GREEN_RED, 1, 100);
				}
//				setTimer(0, 100);
			}
//			break;
		void GREEN_RED(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
//				MODE = MODE2;
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
//				break;
			}
			displayFirstLedCouple(GREEN);
			displaySecondLedCouple(RED);
//			if(timer_flag[0] == 1){
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownFirstCoupleLed == 0){
					countdownFirstCoupleLed = yellowDelay;
//					autostate = YELLOW_RED;
					SCH_Delete_Task(1);
					SCH_Add_Task(YELLOW_RED, 1, 100);
				}
//				setTimer(0, 100);
			}
//			break;
		void YELLOW_RED(){
			if (isButtonPressed(0) == 1 ){
				HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
										  |EN4_Pin|EN5_Pin, GPIO_PIN_SET);
//				MODE = MODE2;
				HAL_GPIO_WritePin(GPIOA, RED1_Pin|YELLOW1_Pin|GREEN1_Pin|RED2_Pin
											  |YELLOW2_Pin|GREEN2_Pin, GPIO_PIN_SET);
				SCH_Delete_Task(0);
				SCH_Delete_Task(1);
				SCH_Add_Task(MODE2, 1, 50);
				SCH_Add_Task(displayIncreaseRed, 1, 50);
				return;
//				break;
			}
			displayFirstLedCouple(YELLOW);
			displaySecondLedCouple(RED);
//			if(timer_flag[0] == 1){
				countdownFirstCoupleLed--;
				countdownSecondCoupleLed--;
				if(countdownFirstCoupleLed == 0){
					countdownSecondCoupleLed = greenDelay;
					countdownFirstCoupleLed = redDelay;
//					autostate = RED_GREEN;
					SCH_Delete_Task(1);
					SCH_Add_Task(RED_GREEN, 1, 100);
				}
//				setTimer(0, 100);
			}
//			break;
//	}
//}
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
//void auto_run(){
//	if(MODE == MODE1){
//		led_fsm();
//		seg_fsm();
//	}
//}
