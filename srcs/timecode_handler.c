#include "../includes/parser.h"

void	update_stamps_start(list *lst, timecode user_convert)
{
	HEURES += user_convert.heures;
	if ((MINUTES += user_convert.minutes) > 60)
	{
		HEURES += 1;
		MINUTES -= 60;
	}
	if ((SECONDS += user_convert.secondes) > 60.0)
	{
		if ((MINUTES += 1) > 60)
		{
			HEURES += 1;
			MINUTES -= 60;
		}
		SECONDS -= 60;
	}
	TOTAL = (HEURES * 3600) + (MINUTES * 60) + SECONDS;
}

void	update_stamps_end(list *lst, timecode user_convert)
{
	HEURES_END += user_convert.heures;
	if ((MINUTES_END += user_convert.minutes) > 60)
	{
		HEURES_END += 1;
		MINUTES_END -= 60;
	}
	if ((SECONDS_END += user_convert.secondes) > 60.0)
	{
		if ((MINUTES_END += 1) > 60)
		{
			HEURES_END += 1;
			MINUTES_END -= 60;
		}
		SECONDS_END -= 60;
	}
	TOTAL_END = (HEURES_END * 3600) + (MINUTES_END * 60) + SECONDS_END;
}

void	handle_input(list *lst, double user_input)
{
	timecode	user_convert;
	double		copy; 

	copy = user_input;
	user_convert.heures = (int)copy / 3600;
	copy -= user_convert.heures * 3600;
	user_convert.minutes = (int)copy / 60;
	copy -= user_convert.minutes * 60;
	user_convert.secondes = copy;
	update_stamps_start(lst, user_convert);
	update_stamps_end(lst, user_convert);
}

void	split_time(list *lst, double *user_input, FILE *fp)
{
	(void)fp;
	lst->timestamp_start[8] = '.';
	HEURES = atoi(lst->timestamp_start);
	MINUTES = atoi(lst->timestamp_start + 3);
	SECONDS = atof(lst->timestamp_start + 6);
	TOTAL = (HEURES * 3600) + (MINUTES * 60) + SECONDS;

	lst->timestamp_end[8] = '.';
	HEURES_END = atoi(lst->timestamp_end);
	MINUTES_END = atoi(lst->timestamp_end + 3);
	SECONDS_END = atof(lst->timestamp_end + 6);
	TOTAL_END = (HEURES_END * 3600) + (MINUTES_END * 60) + SECONDS_END;

	handle_input(lst, *user_input);

}