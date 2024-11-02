/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:58:50 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:15:50 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philo_action(t_philo *philo)
{
	pthread_mutex_lock(&((philo->data->fk)[philo->fk_idx[0]]));
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(&((philo->data->fk)[philo->fk_idx[1]]));
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->philo_lock));
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&(philo->philo_lock));
	print_philo(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&(philo->philo_lock));
	philo->eat_cnt += 1;
	pthread_mutex_unlock(&(philo->philo_lock));
	pthread_mutex_unlock(&((philo->data->fk)[philo->fk_idx[0]]));
	pthread_mutex_unlock(&((philo->data->fk)[philo->fk_idx[1]]));
	print_philo(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
	print_philo(philo, "is thinking");
}

void	*philo_func(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	pthread_mutex_lock(&(philo->data->data_lock));
	pthread_mutex_lock(&(philo->philo_lock));
	philo->last_eat_time = philo->data->start_time;
	pthread_mutex_unlock(&(philo->philo_lock));
	pthread_mutex_unlock(&(philo->data->data_lock));
	if (philo->idx % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	while (chk_death(philo->data) == 0)
		philo_action(philo);
	return (NULL);
}
