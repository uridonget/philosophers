/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:34:30 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:16:53 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	create_thread(t_data *data)
{
	int	i;

	if (pthread_create(&(data->death_chk), NULL, \
	death_chk_func, (void *)(data)))
		return (1);
	if (data->goal != -1)
		if (pthread_create(&(data->finish_chk), NULL, \
		finish_chk_func, (void *)(data)))
			return (1);
	i = 0;
	while (i < data->num)
	{
		if (pthread_create(&(data->philo[i].philo), NULL, \
		philo_func, (void *)&(data->philo[i])))
			return (1);
		i++;
	}
	return (0);
}

static int	join_thread(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join((data->death_chk), NULL))
		return (1);
	if (data->goal != -1)
		if (pthread_join((data->finish_chk), NULL))
			return (1);
	while (i < data->num)
	{
		if (pthread_join((data->philo[i].philo), NULL))
			return (1);
		i++;
	}
	return (0);
}

int	init_thread(t_data *data)
{
	pthread_mutex_lock(&(data->data_lock));
	if (create_thread(data))
	{
		write_err("Error : Thread Create Failed\n");
		return (1);
	}
	data->start_time = get_time();
	pthread_mutex_unlock(&(data->data_lock));
	if (join_thread(data))
	{
		write_err("Error : Thread Join Failed\n");
		return (1);
	}
	return (0);
}
