/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_chk_func_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:03:16 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:06 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*death_chk_func(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	philo->last_eat_time = data->start_time;
	while (1)
	{
		sem_wait(data->data_lock);
		if (philo->last_eat_time + data->time_to_die < get_time())
		{
			sem_wait(data->print_lock);
			printf("%llu %d died\n", get_time() - \
			data->start_time, philo->idx + 1);
			sem_post(data->end_lock);
			exit(EXIT_SUCCESS);
		}
		sem_post(data->data_lock);
		usleep(300);
	}
	return (NULL);
}
