/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:57:10 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 14:20:57 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t *init_forks(int count)
{
	int i;
	pthread_mutex_t *forks;

	forks = malloc(sizeof(pthread_mutex_t) * count);
	if (!forks)
		throw_error(ALLOC_ERORR);
	i = -1;
	while (++i < count)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

t_params *init_params(char **av)
{
	t_params *params;
	
	av++;
	params = malloc(sizeof(t_params));
	if (!params)
		throw_error(ALLOC_ERORR);
	params->count = atoi(av[0]);
	params->die_time = atoi(av[1]);
	params->eat_time = atoi(av[2]);
	params->sleep_time = atoi(av[3]);
	if (av[4])
		params->eat_count = atoi(av[4]);
	else
		params->eat_count = 0;
	return (params);
}

t_philo *init_philos(t_params *params, pthread_mutex_t *forks)
{
	t_philo *philos;
	int		i;
	
	i = -1;
	philos = malloc(sizeof(t_philo) * params->count);
	if (!philos)
		throw_error(ALLOC_ERORR);
	while (++i < params->count)
	{
		philos[i].id = i + 1;
		if (i == params->count - 1)
			philos[i].rfork = &forks[0];
		else
			philos[i].rfork = &forks[i + 1];
		philos[i].lfork = &forks[i];
		philos[i].params = params;
		philos[i].eat_count = params->eat_count;
		philos[i].thread = malloc(sizeof(pthread_t));
		if (!philos[i].thread)
			throw_error(ALLOC_ERORR);
	}
	return (philos);
}

int	init_threads(t_philo *philos, t_params *params, pthread_mutex_t *forks)
{
	t_data *data;
	long int time;
	int i;
	
	i = 0;
	data = malloc(sizeof(t_data));
	data->forks = forks;
	data->params = params;
	data->philos = philos;
	time = get_curr_time();
		
	return (0);
}

