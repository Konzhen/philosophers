/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:32:16 by jbutte            #+#    #+#             */
/*   Updated: 2023/05/29 16:03:54 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philo.h"

unsigned int	ft_atoi_philo(const char *s)
{
	unsigned long	total;
	int				i;

	total = 0;
	i = 0;
	if (!s || !*s)
		return (0);
	if (ft_strlen(s) > 19)
		return (0);
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-')
		return (0);
	else if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
		total = (total * 10) + (s[i] - 48);
		i++;
	}
	if (total > UINT_MAX)
		return (0);
	return ((unsigned int)total);
}
