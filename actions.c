/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:17:20 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 16:06:18 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	eating(t_philo *philo)
{
	unsigned int	eat_time;

	pthread_mutex_lock(philo->data->mutex_storage->m_time);
	eat_time = philo->data->time_to_eat;
	pthread_mutex_unlock(philo->data->mutex_storage->m_time);
	pthread_mutex_lock(philo->fork);
	printing(philo, TAKE_FORK);
	pthread_mutex_lock(philo->next_fork);
	printing(philo, TAKE_FORK);
	pthread_mutex_lock(philo->data->mutex_storage->m_eat_achievement);
	philo->n_eat++;
	pthread_mutex_unlock(philo->data->mutex_storage->m_eat_achievement);
	printing(philo, IS_EATING);
	pthread_mutex_lock(philo->data->mutex_storage->m_death);
	philo->death_limit = get_death_limit(philo);
	pthread_mutex_unlock(philo->data->mutex_storage->m_death);
	usleep_philo(philo, eat_time);
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(philo->fork);
}

void	sleeping(t_philo *philo)
{
	unsigned int	sleep_time;

	pthread_mutex_lock(philo->data->mutex_storage->m_time);
	sleep_time = philo->data->time_to_sleep;
	pthread_mutex_unlock(philo->data->mutex_storage->m_time);
	printing(philo, IS_SLEEPING);
	usleep_philo(philo, sleep_time);
}

void	thinking(t_philo *philo)
{	
	printing(philo, IS_THINKING);
}
