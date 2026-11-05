/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locker_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:30:53 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 12:47:15 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

bool	check_over(t_data *data)
{
	pthread_mutex_lock(data->mutex_storage->m_over);
	if (data->over == false)
	{
		pthread_mutex_unlock(data->mutex_storage->m_over);
		return (false);
	}
	pthread_mutex_unlock(data->mutex_storage->m_over);
	return (true);
}

void	set_over(t_data *data)
{
	pthread_mutex_lock(data->mutex_storage->m_over);
	if (data->over == false)
		data->over = true;
	pthread_mutex_unlock(data->mutex_storage->m_over);
}
