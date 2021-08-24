/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:26:56 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 20:11:42 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "philo.h"

typedef struct	s_philo
{
	pthread_t		*thread;
	pthread_t		*monitor;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	struct s_params	*params;
	long int		start;
	long int		eat;
	int				id;
	int				meals_count;
}				t_philo;

typedef struct	s_params
{
	int count;
	int eat_time;
	int die_time;
	int sleep_time;
	int eat_count;
	int *waiter;
}				t_params;

#endif