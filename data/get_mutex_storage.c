/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mutex_storage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:11:01 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 14:47:14 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

static t_mutex_storage	constructor_mutex_storage(void)
{
	t_mutex_storage	mutex_storage;

	mutex_storage.m_print = NULL;
	mutex_storage.m_eat_achievement = NULL;
	mutex_storage.m_death = NULL;
	mutex_storage.m_over = NULL;
	mutex_storage.m_time = NULL;
	return (mutex_storage);
}

static bool	set_ending_mutex(t_mutex_storage *mutex_storage)
{	
	pthread_mutex_t	*m_eat_achievement;
	pthread_mutex_t	*m_death;
	pthread_mutex_t	*m_over;

	m_eat_achievement = malloc(sizeof(pthread_mutex_t));
	if (!m_eat_achievement || pthread_mutex_init(m_eat_achievement, NULL))
		return (false);
	mutex_storage->m_eat_achievement = m_eat_achievement;
	m_death = malloc(sizeof(pthread_mutex_t));
	if (!m_death || pthread_mutex_init(m_death, NULL))
		return (false);
	mutex_storage->m_death = m_death;
	m_over = malloc(sizeof(pthread_mutex_t));
	if (!m_over || pthread_mutex_init(m_over, NULL))
		return (false);
	mutex_storage->m_over = m_over;
	return (true);
}

static bool	set_controller_mutex(t_mutex_storage *mutex_storage)
{
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*m_time;

	m_print = malloc(sizeof(pthread_mutex_t));
	if (!m_print || pthread_mutex_init(m_print, NULL))
		return (false);
	mutex_storage->m_print = m_print;
	m_time = malloc(sizeof(pthread_mutex_t));
	if (!m_time || pthread_mutex_init(m_time, NULL))
		return (false);
	mutex_storage->m_time = m_time;
	return (true);
}

t_mutex_storage	*get_mutex_storage(void)
{
	t_mutex_storage	*mutex_storage;

	mutex_storage = malloc(sizeof(t_mutex_storage));
	if (!mutex_storage)
		return (NULL);
	*mutex_storage = constructor_mutex_storage();
	if (!set_ending_mutex(mutex_storage))
		return (NULL);
	if (!set_controller_mutex(mutex_storage))
		return (NULL);
	return (mutex_storage);
}
