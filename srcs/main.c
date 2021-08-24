/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:12:41 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 14:16:36 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int my_time(void)
{
	struct timeval tv;
	int t;

	gettimeofday(&tv, NULL);
	t = tv.tv_usec;

	// t = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (t);
}


int main(int argc, char **argv)
{
	t_philo *philos;
	t_params *params;
	pthread_mutex_t *forks;

	
	// if (argc != 5 && argc != 6)
		// throw_error(ARGS_COUNT_ERROR);
	// args_is_valid(argv);
	// params = init_params(argv);
	// forks = init_forks(params->count);
	// philos = init_philos(params, forks);
}		
