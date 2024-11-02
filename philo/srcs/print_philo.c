/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:28:04 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:07:50 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_philo(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->data->death_lock));
	if (philo->data->death == 0)
	{
		pthread_mutex_lock(&(philo->data->print_lock));
		printf("%llu %d %s\n", get_time() - \
		philo->data->start_time, philo->idx + 1, msg);
		pthread_mutex_unlock(&(philo->data->print_lock));
	}
	pthread_mutex_unlock(&(philo->data->death_lock));
}
