/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:23:21 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 16:09:01 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

static t_data	constructor_data(void)
{
	t_data	data;

	data.over = false;
	data.n_of_philo = 0;
	data.time_to_die = 0;
	data.time_to_eat = 0;
	data.time_to_sleep = 0;
	data.needed_n_eat = 0;
	data.start = 0;
	data.mutex_storage = NULL;
	return (data);
}

static bool	check_zero(const char *s)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	while (s[i] == '+')
		i++;
	while (s[i])
	{	
		if (s[i] != '0')
			return (false);
		i++;
	}
	return (true);
}

static bool	add_needed_n_eat(char *argv, t_data *data)
{
	if (!argv)
		return (true);
	if (check_zero(argv))
		return (true);
	data->needed_n_eat = ft_atoi_philo(argv);
	if (!data->needed_n_eat)
		return (false);
	return (true);
}

t_data	*get_data(t_data *data, char **argv)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	*data = constructor_data();
	data->n_of_philo = ft_atoi_philo(argv[1]);
	data->time_to_die = ft_atoi_philo(argv[2]);
	data->time_to_eat = ft_atoi_philo(argv[3]);
	data->time_to_sleep = ft_atoi_philo(argv[4]);
	if (!data->n_of_philo || !data->time_to_die
		|| !data->time_to_eat || !data->time_to_sleep)
		return (NULL);
	if (!add_needed_n_eat(argv[5], data))
		return (NULL);
	data->mutex_storage = get_mutex_storage();
	if (!data->mutex_storage)
		return (NULL);
	data->start = get_start();
	return (data);
}
