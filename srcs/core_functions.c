#include "../includes/parser.h"

void	get_file(int *fd, char **tmp_str, char **to_write, char **rest)
{
	char	c;
	int		size_file;

	c = 0;
	size_file = 0;
	while (read(*fd, &c, 1))
		size_file += 1;
	if ((lseek(*fd, 0, SEEK_SET) == -1))
		exit_on_error();
	if (!(*tmp_str = malloc(size_file + 1)))
		exit_on_error();
	*rest = *tmp_str;
	memset(*tmp_str, 0, size_file + 1);
	read(*fd, *tmp_str, size_file);
	if (!(*to_write = strdup(*tmp_str)))
		exit_on_error();

}

char	*parser(list **lst, char *rest, double user_input, FILE **fp)
{
	char	*token;
	double	nb_lines;
	char	*corrected_input;

	token = NULL;
	corrected_input = NULL;
	nb_lines = 0;
	while ((token = strtok_r(rest, "\n", &rest)))
		save_token(token, lst);
	iterate_list(*lst, &split_time, &user_input, NULL);
	iterate_list(*lst, &print, &nb_lines, *fp);
	fseek(*fp, 0, SEEK_SET);
	if (!(corrected_input = malloc(SIZE_LINE * nb_lines + 1)))
		exit_on_error();
	memset(corrected_input, 0, SIZE_LINE * nb_lines + 1);
	fread(corrected_input, SIZE_LINE * nb_lines + 1, 1, *fp);
	return (corrected_input);
}

void	write_subtitles(char *corrected_input, char *to_write, char *str)
{
	char	*rest;
	char	*rest2;
	char	*token;
	char	*token2;
	FILE	*sub;

	rest = corrected_input;
	rest2 = to_write;
	token = NULL;
	if (str == NULL)
	{
		if (!(sub = fopen("PLACE_HOLDER.srt", "w+")))
			exit_on_error();
	}
	else if (!(sub = fopen(str, "w+")))
			exit_on_error();
	while ((token2 = strtok_r(rest2, "\n\r", &rest2)))
	{
		if (token2[0] == '0')
		{
			token = strtok_r(rest, "\n", &rest);
			fprintf(sub, "%s\n", token);		
		}
		else
			fprintf(sub, "%s\n", token2);
	
	}
	free(str);
	free(corrected_input);
	fclose(sub);

}