/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:07:49 by haejeong          #+#    #+#             */
/*   Updated: 2024/02/17 15:32:13 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_data
{
	int					num;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	unsigned long long	start_time;
	int					food_to_eat;
	pid_t				*pid;
	pthread_t			finish_chk;
	sem_t				*fk;
	sem_t				*print_lock;
	sem_t				*data_lock;
	sem_t				*finish_lock;
	sem_t				*end_lock;
	int					end;
}	t_data;

typedef struct s_philo
{
	int					idx;	
	int					eat_cnt;
	unsigned long long	last_eat_time;
	pthread_t			death_chk;
	t_data				*data;
}	t_philo;

// init_data.c
int					init_data(int ac, char *av[], t_data *data);

// chk_arg.c
int					chk_arg(int ac, char *av[]);

// set_data.c
int					set_data(int ac, char *av[], t_data *data);

// init_sem.c
int					init_sem(t_data *data);

// init_process.c
int					init_process(t_philo *philo);
void				kill_all_process(t_philo *philo);

// philo_func.c
void				philo_func(t_philo *philo);

// death_chk_func.c
void				*death_chk_func(void *arg);

// finish_chk_func.c
int					init_finish_chk(t_philo *philo);
void				*finish_chk_func(void *arg);

// end_philo.c
int					all_sem_unlink(void);
int					all_sem_close(t_data *data);
int					end_philo(t_philo *philo);

// utils.c
unsigned long long	get_time(void);
void				ft_usleep(unsigned long long time);
int					write_err(char *str);
void				print_philo(t_philo *philo, char *msg);

#endif
