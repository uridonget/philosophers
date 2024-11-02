/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_chk_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:03:16 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:39:25 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	death_print(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->death_lock));
	if (philo->data->death == 0)
	{
		pthread_mutex_lock(&(philo->data->print_lock));
		printf("%llu %d died\n", get_time() - philo->data->start_time, \
		philo->idx + 1);
		philo->data->death = 1;
		pthread_mutex_unlock(&(philo->data->print_lock));
	}
	pthread_mutex_unlock(&(philo->data->death_lock));
}

static void	wait_philo_begin(t_data *data)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->num)
		{
			pthread_mutex_lock(&(data->philo[i].philo_lock));
			if (data->philo[i].last_eat_time == 0)
			{
				pthread_mutex_unlock(&(data->philo[i].philo_lock));
				usleep(50);
				continue ;
			}
			pthread_mutex_unlock(&(data->philo[i].philo_lock));
		}
		break ;
	}
}

void	*death_chk_func(void *void_data)
{
	t_data	*data;
	int		i;

	data = (t_data *)void_data;
	pthread_mutex_lock(&(data->data_lock));
	pthread_mutex_unlock(&(data->data_lock));
	wait_philo_begin(data);
	while (chk_death(data) == 0)
	{
		i = -1;
		while (++i < data->num)
		{
			pthread_mutex_lock(&(data->philo[i].philo_lock));
			if (data->philo[i].last_eat_time + data->time_to_die < get_time())
				death_print(&(data->philo[i]));
			pthread_mutex_unlock(&(data->philo[i].philo_lock));
		}
		usleep(10);
	}
	if (data->num == 1)
		pthread_mutex_unlock(&((data->fk)[0]));
	return (NULL);
}
