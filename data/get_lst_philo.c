/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lst_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:22:52 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 15:21:43 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

static t_philo	constructor_philo(void)
{
	t_philo	philo;

	philo.tid = 0;
	philo.start = 0;
	philo.philo_n = 0;
	philo.death_limit = 0;
	philo.n_eat = 0;
	philo.init_skip = false;
	philo.next = NULL;
	return (philo);
}

static t_philo	*set_philo(unsigned int philo_n, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	*philo = constructor_philo();
	philo->data = data;
	philo->start = data->start;
	philo->philo_n = philo_n;
	if (!get_fork(philo))
		return (NULL);
	return (philo);
}

t_philo	*get_lst_philo(t_philo *lst_philo, t_data *data)
{
	t_philo			*tmp;
	unsigned int	philo_n;

	lst_philo = set_philo(1, data);
	if (!lst_philo)
		return (NULL);
	tmp = lst_philo;
	philo_n = 2;
	while (philo_n <= data->n_of_philo)
	{	
		lst_philo->next = set_philo(philo_n, data);
		if (!lst_philo->next)
			return (NULL);
		lst_philo = lst_philo->next;
		philo_n++;
	}
	get_next_fork(tmp);
	return (tmp);
}
