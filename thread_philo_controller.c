/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo_controller.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:15:19 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 15:51:40 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static bool	mono_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex_storage->m_over);
	if (philo->data->n_of_philo == 1)
	{
		pthread_mutex_unlock(philo->data->mutex_storage->m_over);
		pthread_mutex_lock(philo->fork);
		printing(philo, TAKE_FORK);
		usleep(philo->death_limit);
		pthread_mutex_unlock(philo->fork);
		return (true);
	}
	pthread_mutex_unlock(philo->data->mutex_storage->m_over);
	return (false);
}

static void	*thread_routine_philo(void *philo)
{
	t_philo			*p_philo;

	p_philo = (t_philo *)philo;
	pthread_mutex_lock(p_philo->data->mutex_storage->m_death);
	p_philo->death_limit = get_death_limit(p_philo);
	pthread_mutex_unlock(p_philo->data->mutex_storage->m_death);
	if (mono_routine(p_philo))
		return (NULL);
	if (p_philo->init_skip == false)
	{
		thinking(p_philo);
		usleep(10000);
	}
	while (!check_over(p_philo->data))
	{
		eating(p_philo);
		sleeping(p_philo);
		thinking(p_philo);
	}
	return (NULL);
}

static bool	create_thread_philo(t_philo *philo)
{
	if (pthread_create(&philo->tid, NULL, &thread_routine_philo, philo))
		return (false);
	return (true);
}

bool	thread_philo_controller(t_philo *philo)
{
	t_philo	*tmp;

	tmp = philo;
	while (tmp)
	{
		if (tmp->philo_n % 2 == 1)
			tmp->init_skip = true;
		tmp = tmp->next;
	}
	tmp = philo;
	while (tmp)
	{
		if (!create_thread_philo(tmp))
			return (false);
		tmp = tmp->next;
	}
	return (true);
}
