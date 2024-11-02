/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sem_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:03:42 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:57 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	open_fk_print_data(t_data *data)
{
	sem_unlink("/sem_fk");
	data->fk = sem_open("/sem_fk", O_CREAT | O_EXCL, 0644, data->num);
	if (data->fk == SEM_FAILED)
		return (1);
	sem_unlink("/sem_print");
	data->print_lock = sem_open("/sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (data->print_lock == SEM_FAILED)
	{
		sem_close(data->fk);
		return (1);
	}
	sem_unlink("/sem_data");
	data->data_lock = sem_open("/sem_data", O_CREAT | O_EXCL, 0644, 1);
	if (data->data_lock == SEM_FAILED)
	{
		sem_close(data->fk);
		sem_close(data->print_lock);
		return (1);
	}
	return (0);
}

static int	open_finish_end(t_data *data)
{
	sem_unlink("/sem_finish");
	data->finish_lock = sem_open("/sem_finish", \
			O_CREAT | O_EXCL, 0644, 0);
	if (data->finish_lock == SEM_FAILED)
		return (1);
	sem_unlink("/sem_end");
	data->end_lock = sem_open("/sem_end", O_CREAT | O_EXCL, 0644, 0);
	if (data->end_lock == SEM_FAILED)
	{
		sem_close(data->finish_lock);
		return (1);
	}
	return (0);
}

int	init_sem(t_data *data)
{
	if (open_fk_print_data(data))
		return (all_sem_unlink());
	if (open_finish_end(data))
	{
		sem_close(data->fk);
		sem_close(data->print_lock);
		sem_close(data->data_lock);
		return (all_sem_unlink());
	}
	return (0);
}
