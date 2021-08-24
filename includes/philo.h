/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:12:47 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 14:14:25 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ARGS_COUNT_ERROR -1
# define ARG_ERROR -2
# define ALLOC_ERORR -3

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>


# include "struct.h"

void throw_error(int code);

int is_number(char *str);
int args_is_valid(char **av);
int ft_strlen(char *str);
long int	get_curr_time(void);

t_params		*init_params(char **av);
pthread_mutex_t	*init_forks(int count);
t_philo			*init_philos(t_params *params, pthread_mutex_t *forks);

#endif