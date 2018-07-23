#include "../includes/parser.h"

FILE *fp = NULL;
int nb_lines = 0;

int main(int argc, char **argv)
{
	int fd; //stay in main
	long long int size_file; // in struct env
	char buf; // go in parser
	char *tmp_str; // go in parser
	char *to_write; // go in parser
	char *corrected_input; // go in parser
	char *token; // go in parser
	char *rest; // go in parser
	list *lst; // go in parser
	double user_input; // stay in main

	size_file = 0;
	buf = 0;
	lst = NULL;
	user_input = 0.0;
	nb_lines = 0;
	corrected_input = NULL;
	if (argc != 3)
		return (0);
	if (!(fp = tmpfile()))
		exit_on_error();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_on_error();
	while (read(fd, &buf, 1))
		size_file += 1;
	if ((lseek(fd, 0, SEEK_SET) == -1))
		exit_on_error();
	if (!(tmp_str = malloc(size_file + 1)))
		exit_on_error();
	trim_user_input(argv[2]);			
	user_input = atof(argv[2]);
	rest = tmp_str;
	memset(tmp_str, 0, size_file + 1);
	read(fd, tmp_str, size_file);
	to_write = strdup(tmp_str);
	while ((token = strtok_r(rest, "\n", &rest)))
		save_token(token, &lst);
	iterate_list(lst, &split_time, user_input);
	iterate_list(lst, &print, 0);
	fseek(fp, 0, SEEK_SET);
	corrected_input = malloc(SIZE_LINE * nb_lines + 1);
	memset(corrected_input, 0, SIZE_LINE * nb_lines + 1);
	fread(corrected_input, SIZE_LINE * nb_lines + 1, 1, fp);
	close(fd);
	fclose(fp);
}

void	get_file(int fd, char **tmp_str, char **to_write)
{
	char	c;

	c = 0;
	while (read(fd, &buf, 1))
		size_file += 1;
	if ((lseek(fd, 0, SEEK_SET) == -1))
		exit_on_error();
	if (!(*tmp_str = malloc(size_file + 1)))
		exit_on_error();
	memset(*tmp_str, 0, size_file + 1);
	read(fd, tmp_str, size_file);
	if (!(*to_write = strdup(*tmp_str)))
		exit_on_error();
}

void	parser()
{

}