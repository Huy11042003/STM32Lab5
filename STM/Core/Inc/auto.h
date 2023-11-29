/*
 * fsm_auto.h
 *
 *  Created on: Oct 22, 2023
 *      Author: ad
 */

#ifndef INC_AUTO_H_
#define INC_AUTO_H_

#include <display.h>
#include "global.h"
#include "software_timer.h"
#include "button.h"

void led_fsm();
void seg_fsm();
void auto_run();

#endif /* INC_AUTO_H_ */
