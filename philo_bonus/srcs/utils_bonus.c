/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:57:01 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:29:34 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

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

int	write_err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	return (1);
}

void	print_philo(t_philo *philo, char *msg)
{
	sem_wait(philo->data->print_lock);
	printf("%llu %d %s\n", get_time() - \
	philo->data->start_time, philo->idx + 1, msg);
	sem_post(philo->data->print_lock);
}
