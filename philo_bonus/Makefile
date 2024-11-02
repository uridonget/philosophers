CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

SRCS		= ./srcs/main_bonus.c \
			  ./srcs/init_data_bonus.c \
			  ./srcs/chk_arg_bonus.c \
			  ./srcs/set_data_bonus.c \
			  ./srcs/init_sem_bonus.c \
			  ./srcs/init_process_bonus.c \
			  ./srcs/philo_func_bonus.c \
			  ./srcs/death_chk_func_bonus.c \
			  ./srcs/finish_chk_func_bonus.c \
			  ./srcs/end_philo_bonus.c \
			  ./srcs/utils_bonus.c \

OBJS		= $(SRCS:.c=.o)

NAME		= philo_bonus

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
