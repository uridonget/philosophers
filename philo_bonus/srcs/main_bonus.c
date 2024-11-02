/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:46:31 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:56 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static void	init_philo(t_philo *philo, t_data *data)
{
	philo->idx = 0;
	philo->eat_cnt = 0;
	philo->last_eat_time = 0;
	philo->data = data;
}

int	main(int ac, char *av[])
{
	t_data	data;
	t_philo	philo;

	if (init_data(ac, av, &data))
		return (EXIT_FAILURE);
	init_philo(&philo, &data);
	if (data.food_to_eat != -1)
	{
		if (init_finish_chk(&philo))
		{
			end_philo(&philo);
			return (EXIT_FAILURE);
		}
	}
	if (init_process(&philo))
	{
		end_philo(&philo);
		write_err("Error : init_process\n");
		return (EXIT_FAILURE);
	}
	end_philo(&philo);
	return (0);
}
