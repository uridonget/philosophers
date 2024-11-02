/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:34:30 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:31:51 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	kill_all_process(t_philo *philo)
{
	t_data	*data;
	int		i;

	data = philo->data;
	i = 0;
	while (i < data->num)
	{
		kill(data->pid[i], SIGKILL);
		i++;
	}
	philo->data->end = 1;
}

int	init_process(t_philo *philo)
{
	int		i;
	pid_t	now_pid;

	i = -1;
	philo->data->start_time = get_time();
	while (++i < philo->data->num)
	{
		now_pid = fork();
		philo->data->pid[i] = now_pid;
		if (now_pid == -1)
		{
			kill_all_process(philo);
			return (1);
		}
		if (now_pid == 0)
		{
			philo->idx = i;
			philo_func(philo);
			exit(EXIT_SUCCESS);
		}
	}
	sem_wait(philo->data->end_lock);
	kill_all_process(philo);
	return (0);
}
