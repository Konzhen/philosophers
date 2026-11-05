/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_controller.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:16:25 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 15:29:39 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static bool	check_death(t_philo *lst_philo)
{
	t_philo	*tmp;

	tmp = lst_philo;
	while (lst_philo)
	{
		pthread_mutex_lock(tmp->data->mutex_storage->m_death);
		if (lst_philo->death_limit
			&& lst_philo->death_limit < get_time(lst_philo->start))
		{
			set_over(lst_philo->data);
			printing_death(lst_philo);
			pthread_mutex_unlock(tmp->data->mutex_storage->m_death);
			return (true);
		}
		pthread_mutex_unlock(tmp->data->mutex_storage->m_death);
		lst_philo = lst_philo->next;
	}
	return (false);
}

static bool	check_eat_achievement(t_philo *lst_philo)
{
	t_philo	*tmp;

	tmp = lst_philo;
	while (lst_philo)
	{
		pthread_mutex_lock(tmp->data->mutex_storage->m_eat_achievement);
		if (lst_philo->n_eat < lst_philo->data->needed_n_eat)
		{
			pthread_mutex_unlock(tmp->data
				->mutex_storage->m_eat_achievement);
			return (false);
		}
		pthread_mutex_unlock(tmp->data->mutex_storage->m_eat_achievement);
		lst_philo = lst_philo->next;
	}
	set_over(tmp->data);
	return (true);
}

void	checker_controller(t_data *data, t_philo *lst_philo)
{
	while (true)
	{
		if (data->needed_n_eat)
		{
			if (check_eat_achievement(lst_philo))
				break ;
		}
		if (check_death(lst_philo))
			break ;
	}
	free_all(lst_philo, data);
}
