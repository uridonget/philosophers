/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_chk_func_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:15:13 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:16 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	*finish_chk_func(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->num && data->end == 0)
	{
		sem_wait(data->finish_lock);
		i++;
	}
	if (data->end != 0)
		return (NULL);
	sem_wait(data->print_lock);
	printf("------ALL PHILOSOPHERS ARE FULL------\n");
	sem_post(data->end_lock);
	return (NULL);
}

int	init_finish_chk(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (pthread_create(&(data->finish_chk), NULL, \
				finish_chk_func, (void *)(data)) == -1)
		return (1);
	if (pthread_detach(data->finish_chk))
		return (1);
	return (0);
}
