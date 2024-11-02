/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:50:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 15:32:42 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static	int	malloc_data(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * (data->num));
	if (!(data->philo))
		return (1);
	data->fk = malloc(sizeof(pthread_mutex_t) * (data->num));
	if (!(data->fk))
	{
		free(data->philo);
		return (1);
	}
	return (0);
}

static void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		data->philo[i].idx = i;
		data->philo[i].eat_cnt = 0;
		data->philo[i].fk_idx[0] = (data->num - 1 + i) % data->num;
		data->philo[i].fk_idx[1] = (data->num + i) % data->num;
		data->philo[i].last_eat_time = 0;
		data->philo[i].data = data;
		i++;
	}
}

int	init_data(int ac, char *av[], t_data *data)
{	
	if (chk_arg(ac, av))
	{
		write_err("Error : Wrong Argument\n");
		return (1);
	}
	if (set_data(ac, av, data))
	{
		write_err("Error : Wrong Argument\n");
		return (1);
	}
	if (malloc_data(data))
	{
		write_err("Error : Malloc Failed\n");
		return (1);
	}
	if (init_mutex(data))
	{
		write_err("Error : Init Mutex\n");
		free(data->philo);
		free(data->fk);
		return (1);
	}
	init_philo(data);
	return (0);
}
