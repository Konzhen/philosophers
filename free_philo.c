/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:32:49 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 15:46:08 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static void	join_lst_philo(t_philo *lst_philo)
{
	while (lst_philo)
	{
		pthread_join(lst_philo->tid, NULL);
		lst_philo = lst_philo->next;
	}
}

static void	free_lst_philo(t_philo *lst_philo)
{
	t_philo	*tmp;

	while (lst_philo)
	{
		tmp = lst_philo->next;
		pthread_mutex_destroy(lst_philo->fork);
		free(lst_philo->fork);
		free(lst_philo);
		lst_philo = tmp;
	}
}

static void	free_mutex_storage(t_mutex_storage *mutex_storage)
{
	pthread_mutex_destroy(mutex_storage->m_print);
	pthread_mutex_destroy(mutex_storage->m_eat_achievement);
	pthread_mutex_destroy(mutex_storage->m_death);
	pthread_mutex_destroy(mutex_storage->m_over);
	pthread_mutex_destroy(mutex_storage->m_time);
	free(mutex_storage->m_print);
	free(mutex_storage->m_eat_achievement);
	free(mutex_storage->m_death);
	free(mutex_storage->m_over);
	free(mutex_storage->m_time);
	free(mutex_storage);
}

void	free_all(t_philo *lst_philo, t_data *data)
{
	join_lst_philo(lst_philo);
	free_lst_philo(lst_philo);
	free_mutex_storage(data->mutex_storage);
	free(data);
}
