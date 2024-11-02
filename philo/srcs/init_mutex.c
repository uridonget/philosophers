/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:08:43 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:08:20 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_data_lock(t_data *data)
{
	if (pthread_mutex_init(&(data->print_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(data->death_lock), NULL))
	{
		pthread_mutex_destroy(&(data->print_lock));
		return (1);
	}
	if (pthread_mutex_init(&(data->data_lock), NULL))
	{
		pthread_mutex_destroy(&(data->print_lock));
		pthread_mutex_destroy(&(data->death_lock));
		return (1);
	}
	return (0);
}

static int	init_fk(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num)
	{
		if (pthread_mutex_init(&(data->fk[i]), NULL))
			break ;
	}
	if (i < data->num)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&(data->fk[i]));
		return (1);
	}
	return (0);
}

static int	init_philo_lock(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num)
	{
		if (pthread_mutex_init(&(data->philo[i].philo_lock), NULL))
			break ;
	}
	if (i < data->num)
	{
		while (--i >= 0)
			pthread_mutex_destroy(&(data->philo[i].philo_lock));
		return (1);
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	if (init_data_lock(data))
		return (1);
	if (init_fk(data))
	{
		pthread_mutex_destroy(&(data->print_lock));
		pthread_mutex_destroy(&(data->death_lock));
		pthread_mutex_destroy(&(data->data_lock));
		return (1);
	}
	if (init_philo_lock(data))
	{
		pthread_mutex_destroy(&(data->print_lock));
		pthread_mutex_destroy(&(data->death_lock));
		pthread_mutex_destroy(&(data->data_lock));
		while (i < data->num)
		{
			pthread_mutex_destroy(&(data->fk[i]));
			i++;
		}
		return (1);
	}
	return (0);
}
