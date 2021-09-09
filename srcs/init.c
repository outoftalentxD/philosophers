/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:57:10 by melaena           #+#    #+#             */
/*   Updated: 2021/09/09 21:20:16 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*pmute_init(void)
{
	pthread_mutex_t	*pmute;

	pmute = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!pmute)
	{
		throw_error(ALLOC_ERORR);
		return (0);
	}
	if (pthread_mutex_init(pmute, NULL))
	{
		throw_error(MUTEX_INIT_ERROR);
		return (0);
	}
	return (pmute);
}

pthread_mutex_t	*init_forks(int count)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = ft_calloc(count, sizeof(pthread_mutex_t));
	if (!forks)
	{
		throw_error(ALLOC_ERORR);
		return (0);
	}
	i = -1;
	while (++i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			throw_error(MUTEX_INIT_ERROR);
	}
	return (forks);
}

t_params	*init_params(char **av)
{
	t_params		*params;

	av++;
	params = ft_calloc(1, sizeof(t_params));
	if (!params)
		return (NULL);
	params->count = ft_atoi(av[0]);
	params->die_time = ft_atoi(av[1]);
	params->eat_time = ft_atoi(av[2]);
	params->sleep_time = ft_atoi(av[3]);
	if (av[4])
		params->meals_count = ft_atoi(av[4]);
	else
		params->meals_count = 0;
	params->pmute = pmute_init();
	params->monitor = ft_calloc(1, sizeof(pthread_t));
	if (!params->monitor)
		return (NULL);
	params->death = 0;
	params->finished = 0;
	return (params);
}

t_philo	*init_philos(t_params *params, pthread_mutex_t *forks)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = ft_calloc(params->count, sizeof(t_philo));
	if (!philos)
		return (0);
	while (++i < params->count)
	{
		philos[i].id = i + 1;
		if (i == params->count - 1)
			philos[i].rfork = &forks[0];
		else
			philos[i].rfork = &forks[i + 1];
		philos[i].lfork = &forks[i];
		philos[i].params = params;
		philos[i].meals_count = 0;
		philos[i].thread = ft_calloc(1, sizeof(pthread_t));
		if (!philos[i].thread)
			return (0);
	}
	return (philos);
}

int	init_threads(t_philo *philos, t_params *params)
{
	long int	time;
	int			i;

	time = get_curr_time();
	i = -1;
	while (++i < params->count)
	{
		philos[i].start = time;
		philos[i].eat = time;
		if (pthread_create(philos[i].thread, NULL,
				(void *)action, (void *)&philos[i]))
			return (throw_error(PTHREAD_START_ERROR));
		if (pthread_detach(*(philos[i].thread)))
			return (throw_error(PTHREAD_DETACH_ERROR));
		usleep(100);
	}
	usleep(200);
	if (pthread_create(params->monitor, NULL, (void *)monitor, (void *)philos))
		return (throw_error(PTHREAD_START_ERROR));
	if (pthread_join(*(params->monitor), NULL))
		return (throw_error(PTHREAD_JOIN_ERROR));
	return (0);
}
