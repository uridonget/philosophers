/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:57:01 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:07:46 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned long long	get_time(void)
{
	struct timeval		time;
	unsigned long long	sec;
	unsigned long long	usec;

	gettimeofday(&time, NULL);
	sec = time.tv_sec * 1000;
	usec = time.tv_usec / 1000;
	return (sec + usec);
}

void	ft_usleep(unsigned long long time)
{
	unsigned long long	start;

	start = get_time();
	usleep(time * 500);
	while (get_time() - start < time)
		usleep(100);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		pthread_mutex_destroy(&(data->philo[i].philo_lock));
		pthread_mutex_destroy(&(data->fk[i]));
		i++;
	}
	pthread_mutex_destroy(&(data->print_lock));
	pthread_mutex_destroy(&(data->death_lock));
	pthread_mutex_destroy(&(data->data_lock));
	free(data->philo);
	free(data->fk);
}

int	chk_death(t_data *data)
{
	pthread_mutex_lock(&(data->death_lock));
	if (data->death == 0)
	{
		pthread_mutex_unlock(&(data->death_lock));
		return (0);
	}
	pthread_mutex_unlock(&(data->death_lock));
	return (1);
}

void	write_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}
