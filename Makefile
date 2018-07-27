NAME = 		subtitle_modifier

SRCS = 		parse_subtitle.c \
			timecode_handler.c \
			list_token.c \
			misc_functions.c \
			core_functions.c

OBJS = 		$(SRCS:.c=.o)

SRCPATH = 	./srcs/

INCPATH =	./includes/

FLAGS = 	

all : 		$(NAME)

$(NAME) :	$(addprefix $(SRCPATH), $(SRCS))
			@gcc $(FLAGS) -c $(addprefix $(SRCPATH), $(SRCS)) -I $(INCPATH)
			@printf "\033[0;34m> Compiling Program\033[0m"
			@gcc $(FLAGS) $(OBJS) -o $(NAME)
			@printf "\033[0;32m OK\n\033[0m"
			@rm $(OBJS)
clean :
			@rm -rf $(OBJS)

fclean :	clean
			@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
