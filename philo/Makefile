CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= ./srcs/main.c \
			  ./srcs/utils.c \
			  ./srcs/print_philo.c \
			  ./srcs/chk_arg.c \
			  ./srcs/set_data.c \
			  ./srcs/init_mutex.c \
			  ./srcs/init_data.c \
			  ./srcs/init_thread.c \
			  ./srcs/philo_func.c \
			  ./srcs/death_chk_func.c \
			  ./srcs/finish_chk_func.c \

OBJS		= $(SRCS:.c=.o)

NAME		= philo

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean 	:
	$(RM) $(OBJS)

fclean 	: clean
	$(RM) $(NAME)

re 		:
	make fclean
	make all

.PHONY : all clean fclean re
