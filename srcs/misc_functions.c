#include "../includes/parser.h"

int		exit_on_error(void)
{
	perror("");
	exit(0);
}

void	trim_user_input(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '.' && str[i] != ',')
		i++;
	if (str[i] == ',')
		str[i] = '.';
	if (strlen(str) > i + 4)
		str[i + 4] = '\0';
}

char	*create_file_name(char *str)
{
	size_t 	i;
	size_t 	size;
	char	*new_name;

	size = strlen(str);
	new_name = NULL;
	i = size - 1;
	while (i > 0 && str[i] && str[i] != '/')
		i--;
	if (i == 0)
		i = size;
	else
		i++;
	if (!(new_name = malloc(size - i + 10)))
		return (NULL);
	memset(new_name, 0, size - i + 10);
	strcpy(new_name, str + i);
	new_name[size - i] = '_';
	new_name[size - i + 1] = 'n';
	new_name[size - i + 2] = 'e';
	new_name[size - i + 3] = 'w';
	new_name[size - i + 4] = '.';
	new_name[size - i + 5] = 's';
	new_name[size - i + 6] = 'r';
	new_name[size - i + 7] = 't';
	return (new_name);

}