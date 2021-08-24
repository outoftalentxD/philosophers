/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:26:56 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 14:20:33 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "philo.h"

typedef struct	s_philo
{
	pthread_t		*thread;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*lfork;
	struct s_params	*params;
	int				id;
	int				eat_count;
}				t_philo;

typedef struct	s_params
{
	int count;
	int eat_time;
	int die_time;
	int sleep_time;
	int eat_count;
}				t_params;

typedef struct	s_data
{
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
	struct s_params	*params;
	
}				t_data;

#endif