/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:58:50 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:55 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	philo_action(t_philo *philo)
{
	if (philo->eat_cnt == philo->data->food_to_eat)
		sem_post(philo->data->finish_lock);
	while (1)
	{
		sem_wait(philo->data->fk);
		print_philo(philo, "has taken a fork");
		sem_wait(philo->data->fk);
		print_philo(philo, "has taken a fork");
		sem_wait(philo->data->data_lock);
		philo->last_eat_time = get_time();
		sem_post(philo->data->data_lock);
		print_philo(philo, "is eating");
		ft_usleep(philo->data->time_to_eat);
		sem_wait(philo->data->data_lock);
		philo->eat_cnt += 1;
		if (philo->eat_cnt == philo->data->food_to_eat)
			sem_post(philo->data->finish_lock);
		sem_post(philo->data->data_lock);
		sem_post(philo->data->fk);
		sem_post(philo->data->fk);
		print_philo(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print_philo(philo, "is thinking");
	}
}

void	philo_func(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (pthread_create(&(philo->death_chk), NULL, \
				death_chk_func, (void *)(philo)) == -1)
	{
		end_philo(philo);
		exit(EXIT_FAILURE);
	}
	if (pthread_detach(philo->death_chk))
		end_philo(philo);
	if (philo->idx % 2 == 0)
		ft_usleep(data->time_to_eat / 2);
	philo_action(philo);
}
