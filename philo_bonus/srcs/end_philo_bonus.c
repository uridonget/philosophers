/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:40:10 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:10 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	all_sem_unlink(void)
{
	sem_unlink("/sem_fk");
	sem_unlink("/sem_print");
	sem_unlink("/sem_data");
	sem_unlink("/sem_finish");
	sem_unlink("/sem_end");
	return (1);
}

int	all_sem_close(t_data *data)
{
	sem_post(data->finish_lock);
	sem_close(data->finish_lock);
	sem_close(data->fk);
	sem_close(data->print_lock);
	sem_close(data->data_lock);
	sem_close(data->end_lock);
	return (1);
}

int	end_philo(t_philo *philo)
{
	all_sem_close(philo->data);
	all_sem_unlink();
	free(philo->data->pid);
	return (0);
}
