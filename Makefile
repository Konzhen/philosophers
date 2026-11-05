NAME = philo

CC = clang -pthread

FLAGS = -g -Wall -Wextra -Werror

SRCS =	philo.c						\
		free_philo.c				\
		checker_controller.c		\
		thread_philo_controller.c	\
		locker_thread.c				\
		printing.c					\
		actions.c					\
		utils/err_std.c				\
		utils/ft_atoi_philo.c		\
		utils/ft_strlen.c			\
		utils/check_argc.c			\
		utils/free_tab.c			\
		data/get_data.c				\
		data/get_fork.c				\
		data/get_lst_philo.c		\
		data/get_timer.c			\
		data/get_mutex_storage.c	\

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re bonus
