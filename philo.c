/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:54:31 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/28 20:41:49 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

static bool	set_vars(t_data **data, t_philo **lst_philo, char **argv)
{
	*data = get_data(*data, argv);
	if (!*data)
	{
		err_std("Wrong argument as parameter");
		return (false);
	}
	*lst_philo = get_lst_philo(*lst_philo, *data);
	if (!*lst_philo)
	{
		err_std("malloc error");
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_data			*data;
	t_philo			*lst_philo;

	if (check_argc(argc, 5, 6))
		return (1);
	data = NULL;
	lst_philo = NULL;
	if (!set_vars(&data, &lst_philo, argv))
		return (1);
	if (!thread_philo_controller(lst_philo))
		return (1);
	checker_controller(data, lst_philo);
	return (0);
}
