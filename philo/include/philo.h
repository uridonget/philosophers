/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:07:49 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/11 16:06:29 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct s_data		*data;
	pthread_t			philo;
	int					idx;
	int					eat_cnt;
	int					fk_idx[2];
	unsigned long long	last_eat_time;
	pthread_mutex_t		philo_lock;
}	t_philo;

typedef struct s_data
{
	t_philo				*philo;
	pthread_t			finish_chk;
	pthread_t			death_chk;
	int					num;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	start_time;
	int					goal;
	int					death;
	pthread_mutex_t		*fk;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		data_lock;
}	t_data;

// chk_arg.c
int					chk_arg(int ac, char *av[]);

// set_data.c
int					set_data(int ac, char *av[], t_data *data);

// init_mutex.c
int					init_mutex(t_data *data);

// init_data.c
int					init_data(int ac, char *av[], t_data *data);

// init_thread.c
int					init_thread(t_data *data);

// philo_func.c
void				*philo_func(void *void_philo);

// death_chk_func.c
void				*death_chk_func(void *void_data);

// finish_func.c
void				*finish_chk_func(void *void_data);

// print_philo.c
void				print_philo(t_philo *philo, char *msg);

// utils.c
unsigned long long	get_time(void);
void				ft_usleep(unsigned long long time);
void				free_all(t_data *data);
void				write_err(char *str);
int					chk_death(t_data *data);

#endif
