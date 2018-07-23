#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

#define HEURES		lst->stamp[0].heures
#define MINUTES		lst->stamp[0].minutes
#define SECONDS		lst->stamp[0].secondes
#define TOTAL		lst->stamp[0].total_in_sec

#define HEURES_END	lst->stamp[1].heures
#define MINUTES_END lst->stamp[1].minutes
#define SECONDS_END lst->stamp[1].secondes
#define TOTAL_END	lst->stamp[1].total_in_sec
#define SIZE_LINE	30

typedef struct		timestamp
{
	int				heures;
	int				minutes;
	double			secondes;
	double			total_in_sec;
}					timecode;

typedef struct	list
{
	char			*timestamp_start;
	char			*timestamp_end;
	char			*whole;
	timecode		stamp[2];
	struct list 	*next;
}					list;

/*
** MISC
*/

int					exit_on_error(void);
void				trim_user_input(char *str);

/*
** HANDLE TIME STAMPS
*/

void				update_stamps_start(list *lst, timecode user_convert);
void				update_stamps_end(list *lst, timecode user_convert);
double				handle_input(list *lst, double user_input);
void				split_time(list *lst, double user_input);

/*
** LIST FUNCTIONS
*/

list				*create_node(const char *src);
void				save_token(const char *src, list **lst);
void				print(list *elem, double empty);
void				iterate_list(list *lst, void (*funcptr)(list *, double), double user_input);

#endif