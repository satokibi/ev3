/**
 * This sample program shows how to create and control periodic tasks in EV3RT
 */

#include "app.h"
#include <stdlib.h>

int16_t distance = 0;

// a cyclic handler to activate a task
void task_activator(intptr_t tskid) {
	ER ercd = act_tsk(tskid);
	assert(ercd == E_OK);
}


int aaa = 0;
void periodic_task_1(intptr_t unused) {
	distance = ev3_ultrasonic_sensor_get_distance(EV3_PORT_1);

	char msgbuf[100];
	aaa += 1;
	sprintf(msgbuf, "Distance: %-3d cm, %d", distance, aaa);
	ev3_lcd_draw_string(msgbuf, 0, 5);

}

// a periodic task
void periodic_task_2(intptr_t unused) {
	uint16_t freq;

	if(distance < 5)
		freq = 0;
	else if(distance < 30)
		freq = NOTE_C4;
	else if(distance < 40)
		freq = NOTE_D4;
	else if(distance < 50)
		freq = NOTE_E4;
	else if(distance < 60)
		freq = NOTE_F4;
	else if(distance < 70)
		freq = NOTE_G4;
	else if(distance < 80)
		freq = NOTE_A4;
	else if(distance < 90)
		freq = NOTE_B4;
	else if(distance < 100)
		freq = NOTE_C5;
	else
		freq = 0;

	if(freq ==0)
		ev3_speaker_stop();
	else
		ev3_speaker_play_tone(freq,100);
}

void main_task(intptr_t unused) {
	ev3_sensor_config(EV3_PORT_1, ULTRASONIC_SENSOR);
}
