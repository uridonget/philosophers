/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:50:54 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:21 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	init_data(int ac, char *av[], t_data *data)
{
	if (chk_arg(ac, av))
		return (write_err("Error : chk_arg\n"));
	if (set_data(ac, av, data))
		return (write_err("Error : set_data\n"));
	if (init_sem(data))
	{
		free(data->pid);
		return (write_err("Error : init_sem\n"));
	}
	return (0);
}
