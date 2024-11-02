/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_chk_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:02:42 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:15:32 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	finish_defined(t_data *data)
{
	pthread_mutex_lock(&(data->death_lock));
	data->death = 1;
	pthread_mutex_lock(&(data->print_lock));
	printf("------ALL PHILOSOPHERS ARE FULL------\n");
	pthread_mutex_unlock(&(data->death_lock));
	pthread_mutex_unlock(&(data->print_lock));
}

static int	get_finished(t_data *data)
{
	int	finished;
	int	i;

	i = 0;
	finished = 0;
	while (i < data->num)
	{
		pthread_mutex_lock(&(data->philo[i].philo_lock));
		if (data->goal <= (data->philo)[i].eat_cnt)
			finished += 1;
		pthread_mutex_unlock(&(data->philo[i].philo_lock));
		i++;
	}
	return (finished);
}

void	*finish_chk_func(void *void_data)
{
	t_data	*data;
	int		finished;

	data = (t_data *)void_data;
	while (chk_death(data) == 0)
	{
		finished = get_finished(data);
		if (finished == data->num)
			finish_defined(data);
		usleep(50);
	}
	return (NULL);
}
