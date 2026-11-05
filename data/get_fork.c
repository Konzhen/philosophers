/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:35:48 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 15:54:32 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

bool	get_fork(t_philo *philo)
{
	pthread_mutex_t	*fork;

	fork = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(fork, NULL))
		return (false);
	philo->fork = fork;
	return (true);
}

static pthread_mutex_t	*set_next_fork(t_philo *philo)
{
	pthread_mutex_t	*fork;

	fork = philo->fork;
	return (fork);
}

void	get_next_fork(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (philo->next)
	{
		philo->next_fork = set_next_fork(philo->next);
		philo = philo->next;
	}
	philo->next_fork = tmp->fork;
}
