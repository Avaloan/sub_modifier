#include "../includes/parser.h"

int		exit_on_error(void)
{
	perror("");
	exit(0);
}

void	trim_user_input(char *str)
{
	size_t i = 0;

	while (str[i] && str[i] != '.' && str[i] != ',')
		i++;
	if (str[i] == ',')
		str[i] = '.';
	if (strlen(str) > i + 4)
		str[i + 4] = '\0';
}
