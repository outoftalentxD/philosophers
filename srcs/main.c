/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:12:41 by melaena           #+#    #+#             */
/*   Updated: 2021/09/09 21:18:38 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philos(t_philo *philos, pthread_mutex_t *forks)
{
	int	i;
	int	count;

	count = philos[0].params->count;
	i = -1;
	pthread_mutex_destroy(philos->params->pmute);
	free(philos[0].params->pmute);
	free(philos[0].params->monitor);
	free(philos[0].params);
	while (++i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		free(philos[i].thread);
	}
	free(forks);
	free(philos);
	exit(0);
}	

int	main(int argc, char **argv)
{
	t_philo				*philos;
	t_params			*params;
	pthread_mutex_t		*forks;

	if (argc != 5 && argc != 6)
		throw_error(ARGS_COUNT_ERROR);
	args_is_valid(argv);
	params = init_params(argv);
	forks = init_forks(params->count);
	philos = init_philos(params, forks);
	init_threads(philos, params);
	free_philos(philos, forks);
	return (0);
}
