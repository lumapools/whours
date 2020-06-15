#include "stop_timer.h"
#include "date.h"
#include "stop_timer_helpers.h"
#include <stdio.h>
#include "time.h"

void proc_stop(void) {
	FILE* f_start = fopen(FILE_START, "r");
	if(f_start == NULL) {
		printf("| WBot> The timer has not been started yet.\n");
		return;
	}
	
	int start_min;
	fscanf(f_start, "%d", &start_min);
	int mins_now = get_nb_mins(get_time());
	int total_work = mins_now - start_min;
	if(total_work < 0) {
		int day1_mins = 1440 - start_min;
		int day2_mins = mins_now;
		write_new_day(day1_mins, day2_mins);
	}
	else {
		write_no_new_day(total_work);
	}
	remove(FILE_START);
	printf("| WBot> The timer has been stopped. You can safely quit the program.\n");
}