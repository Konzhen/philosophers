/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:19:28 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 15:30:25 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	printing_death(t_philo *philo)
{
	pthread_mutex_lock(philo->data->mutex_storage->m_print);
	printf("%ld %i %s\n",
		get_time(philo->start), philo->philo_n, DIED);
	pthread_mutex_unlock(philo->data->mutex_storage->m_print);
}

void	printing(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->mutex_storage->m_print);
	if (!check_over(philo->data))
	{
		printf("%ld %i %s\n",
			get_time(philo->start), philo->philo_n, str);
	}
	pthread_mutex_unlock(philo->data->mutex_storage->m_print);
}
