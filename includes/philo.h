/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:12:47 by melaena           #+#    #+#             */
/*   Updated: 2021/09/09 21:14:54 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ARGS_COUNT_ERROR -1
# define ARG_ERROR -2
# define ALLOC_ERORR -3
# define MUTEX_INIT_ERROR -4
# define PTHREAD_START_ERROR -5
# define PTHREAD_DETACH_ERROR -7
# define PTHREAD_JOIN_ERROR -8

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# include "struct.h"

int				throw_error(int code);
long int		get_curr_time(void);
void			my_usleep(int val);
void			print_status(const char *arg, long int time, t_philo *philo);

int				args_is_valid(char **av);
int				is_number(char *str);
int				ft_strlen(char *str);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);

t_params		*init_params(char **av);
pthread_mutex_t	*init_forks(int count);
t_philo			*init_philos(t_params *params, pthread_mutex_t *forks);
int				init_threads(t_philo *philos, t_params *params);

int				take_forks(t_philo *philo);
int				release_forks(t_philo *philo);

void			monitor(t_philo *philo);

void			action(t_philo *philo);
void			action_eat(t_philo *philo);
void			action_sleep(t_philo *philo);

#endif
