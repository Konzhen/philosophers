/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:37:32 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 16:09:03 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

unsigned long	get_start(void)
{
	struct timeval	tv;
	unsigned long	sec;
	unsigned long	msec;
	unsigned long	time;	

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec * 1000;
	msec = tv.tv_usec / 1000;
	time = (sec + msec);
	return (time);
}

unsigned long	get_time(unsigned long start)
{
	struct timeval	tv;
	unsigned long	sec;
	unsigned long	msec;
	unsigned long	time;	

	gettimeofday(&tv, NULL);
	sec = tv.tv_sec * 1000;
	msec = tv.tv_usec / 1000;
	time = (sec + msec) - start;
	return (time);
}

unsigned long	get_death_limit(t_philo *philo)
{
	unsigned long	death_limit;

	death_limit = get_time(philo->start) + philo->data->time_to_die;
	return (death_limit);
}

void	usleep_philo(t_philo *philo, unsigned int time_to_wait)
{
	unsigned long	ttw;

	ttw = get_time(philo->start) + time_to_wait;
	while (get_time(philo->start) < ttw
		&& get_time(philo->start) < philo->death_limit)
		usleep(1000);
}
