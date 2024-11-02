/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:00:33 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:54 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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
		data->food_to_eat = ft_atoi(av[5]);
	}
	else
		data->food_to_eat = -1;
	data->pid = malloc(sizeof(pid_t) * data->num);
	if (!(data->pid))
		return (1);
	memset(data->pid, 0, sizeof(pid_t) * data->num);
	data->end = 0;
	return (0);
}
