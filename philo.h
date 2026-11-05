/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:02:19 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 14:40:19 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

//-------------------------------------------------------//
//   ~ INCLUDES ~   //

# include <stdbool.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

//-------------------------------------------------------//
//   ~ DEFINES ~   //

//	Vars
# define TAKE_FORK "has taken a fork"
# define IS_EATING "is eating"
# define IS_SLEEPING "is sleeping"
# define IS_THINKING "is thinking"
# define DIED "died"

//-------------------------------------------------------//
//   ~ STRUCTS ~   //

typedef struct s_data
{
	bool					over;
	unsigned int			n_of_philo;
	unsigned int			time_to_die;
	unsigned int			time_to_eat;
	unsigned int			time_to_sleep;
	unsigned int			needed_n_eat;
	unsigned long			start;
	struct s_mutex_storage	*mutex_storage;

}				t_data;

typedef struct s_mutex_storage
{
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_eat_achievement;
	pthread_mutex_t	*m_death;
	pthread_mutex_t	*m_over;
	pthread_mutex_t	*m_time;
}				t_mutex_storage;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		tid;
	unsigned long	start;
	unsigned int	philo_n;
	unsigned long	death_limit;
	unsigned int	n_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*next_fork;
	bool			init_skip;
	struct s_philo	*next;
}				t_philo;

//-------------------------------------------------------//
//   ~ FUNCTIONS ~   //

//	philo.c
int				main(int argc, char **argv);

//	actions.c
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);

//	checker_controller.c
void			checker_controller(t_data *data, t_philo *lst_philo);

//	printing.c
void			printing_death(t_philo *philo);
void			printing(t_philo *philo, char *str);

//	locker_thread.c
bool			check_over(t_data *data);
void			set_over(t_data *data);

//	thread_philo_manager.c
bool			thread_philo_controller(t_philo *lst_philo);

//free_philo.c
void			free_all(t_philo *lst_philo, t_data *data);

//-------------------------------------------------./data//

//	get_data.c
t_data			*get_data(t_data *data, char **argv);

//	get_mutex_storage.c
t_mutex_storage	*get_mutex_storage(void);

//	get_lst_philo.c
t_philo			*get_lst_philo(t_philo *lst_philo, t_data *data);

//	get_fork.c
bool			get_fork(t_philo *philo);
void			get_next_fork(t_philo *philo);

//	get_timer.c
unsigned long	get_start(void);
unsigned long	get_time(unsigned long start);
unsigned long	get_death_limit(t_philo *philo);
void			usleep_philo(t_philo *philo, unsigned int time_to_wait);

//-------------------------------------------------./utils//

int				check_argc(int argc, unsigned int min, unsigned int max);
void			err_std(const char *str);
int				free_tab(void **tab, size_t size);
unsigned int	ft_atoi_philo(const char *s);
size_t			ft_strlen(const char *str);

#endif
