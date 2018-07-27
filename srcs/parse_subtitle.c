#include "../includes/parser.h"

int		main(int argc, char **argv)
{
	int				fd;
	FILE			*fp;
	double			user_input;
	char 			*tmp_str;
	char 			*to_write;
	char 			*rest;
	list 			*lst;
	char			*new;
	char			*new_file_name;
	char			*corrected_input;

	lst = NULL;
	user_input = 0.0;
	rest = NULL;
	corrected_input = NULL;
	fp = NULL;
	if (argc != 3)
		return (0);
	if (strlen(argv[2]) > 8)
		return (0);
	trim_user_input(argv[2]);
	user_input = atof(argv[2]);
	new_file_name = create_file_name(argv[1]);
	if (!(fp = tmpfile()))
		exit_on_error();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_on_error();
	get_file(&fd, &tmp_str, &to_write, &rest);
	corrected_input = parser(&lst, rest, user_input, &fp);
	write_subtitles(corrected_input, to_write, new_file_name);
	free(tmp_str);
	free(to_write);
	free_list_str(lst);
	close(fd);
	fclose(fp);
}
