/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:46:31 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:42:31 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (init_data(ac, av, &data))
		return (EXIT_FAILURE);
	if (init_thread(&data))
	{
		free_all(&data);
		return (EXIT_FAILURE);
	}
	free_all(&data);
	return (0);
}
