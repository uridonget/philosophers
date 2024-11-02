/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:00:33 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/12 10:07:27 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(const char *str)
{
	long long	num;

	num = 0;
	while (*str)
	{
		num = 10 * num + (*str - '0');
		str++;
	}
	if ((num < 0) || (2147483647 < num))
		return (-1);
	return ((int)num);
}

int	set_data(int ac, char *av[], t_data *data)
{	
	if ((ft_atoi(av[1]) < 1) || (ft_atoi(av[2]) == -1) || \
		(ft_atoi(av[3]) == -1) || (ft_atoi(av[4]) == -1))
		return (1);
	data->num = ft_atoi(av[1]);
	data->time_to_die = (unsigned long long)ft_atoi(av[2]);
	data->time_to_eat = (unsigned long long)ft_atoi(av[3]);
	data->time_to_sleep = (unsigned long long)ft_atoi(av[4]);
	if (ac == 6)
	{
		if (ft_atoi(av[5]) == -1)
			return (1);
		data->goal = ft_atoi(av[5]);
	}
	else
		data->goal = -1;
	data->death = 0;
	data->start_time = 0;
	return (0);
}
