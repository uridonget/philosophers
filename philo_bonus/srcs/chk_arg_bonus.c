/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_arg_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:37:21 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:29:52 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

static int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!(str))
		return (1);
	while (str[i])
	{
		if ((str[i] < '0') || ('9' < str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	chk_arg(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (1);
	if (is_num(av[1]) || is_num(av[2]) || is_num(av[3]) || is_num(av[4]))
		return (1);
	if (ac == 6)
	{
		if (is_num(av[5]))
			return (1);
	}
	return (0);
}
