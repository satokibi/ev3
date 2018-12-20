/**
 * This sample program balances a two-wheeled Segway type robot such as Gyroboy in EV3 core set.
 *
 * References:
 * http://www.hitechnic.com/blog/gyro-sensor/htway/
 * http://www.cs.bgu.ac.il/~ami/teaching/Lejos-2013/classes/src/lejos/robotics/navigation/Segoway.java
 */

#include "ev3api.h"
#include "app.h"
#include "stdlib.h"

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

void sub_task(intptr_t unused) {
	int i = 0;
    while(1) {
		if(i != 0) {
			ev3_led_set_color(LED_RED);
		} else {
			ev3_led_set_color(LED_GREEN);
		}
		i = (i + 1) % 2;
    	tslp_tsk(500);
    }
}

void idle_task(intptr_t unused) {
    while(1) {
    	tslp_tsk(1000);
    }
}

void main_task(intptr_t unused) {

	int cnt = 0;
	char buf[32];

    // Draw information
    lcdfont_t font = EV3_FONT_MEDIUM;
    ev3_lcd_set_font(font);

    // Start task for self-balancing
    act_tsk(SUB_TASK);

    // Start task for printing message while idle
	act_tsk(IDLE_TASK);

    while(1) {
		itoa(cnt, buf, 10);
		ev3_lcd_draw_string(buf, 0, 0);
		cnt = cnt + 1;
		tslp_tsk(100);
    }
}
