/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:16:56 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 20:21:23 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void action_eat(t_philo *philo)
{
	long int time;

	time = get_curr_time() - philo->start;
	printf("%ld philosopher [%d] is eating\n", time, philo->id);
	usleep(philo->params->eat_time * 1000);
	philo->eat = get_curr_time();
}

void action_sleep(t_philo *philo)
{
	long int time;

	time = get_curr_time() - philo->start;
	printf("%ld philosopher [%d] is sleeping\n", time, philo->id);
	usleep(philo->params->sleep_time * 1000);
}

void action(t_philo *philo)
{
	static int count;
	long int time;

	pthread_create(philo->monitor, NULL, (void *)monitor, (void *)philo);
	while (1)
	{
		if (take_forks(philo))
		{	
			time = get_curr_time() - philo->start;
			printf("%ld philosopher [%d] has taken a fork\n", time, philo->id);
			printf("%ld philosopher [%d] has taken a fork\n", time, philo->id);
			action_eat(philo);
			release_forks(philo);
			action_sleep(philo);
		}
	}
}	
