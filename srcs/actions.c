/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:16:56 by melaena           #+#    #+#             */
/*   Updated: 2021/08/26 22:23:00 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(const char *arg, long int time, t_philo *philo)
{
	if (philo->params->death == 0)
	{
		pthread_mutex_lock(philo->params->pmute);
		printf(arg, time, philo->id);
		pthread_mutex_unlock(philo->params->pmute);
	}
}

void	my_usleep(int val)
{
	struct timeval	start;
	struct timeval	curr;

	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(50);
		gettimeofday(&curr, NULL);
		if ((curr.tv_sec - start.tv_sec) * 1000000
			+ curr.tv_usec - start.tv_usec >= val)
			return ;
	}
}

void	action_eat(t_philo *philo)
{
	philo->eat = get_curr_time();
	if (philo->params->death == 0)
		print_status("%ld philosopher %d is eating\n",
			philo->eat - philo->start, philo);
	philo->meals_count += 1;
	if (philo->meals_count == philo->params->meals_count)
	{
		philo->params->finished += 1;
		if (philo->params->finished == philo->params->count)
			pthread_mutex_lock(philo->params->pmute);
	}
	my_usleep(philo->params->eat_time * 1000);
}

void	action_sleep(t_philo *philo)
{
	if (philo->params->death == 0)
		print_status("%ld philosopher %d is sleeping\n",
			get_curr_time() - philo->start, philo);
	my_usleep(philo->params->sleep_time * 1000);
	if (philo->params->death == 0)
		print_status("%ld philosopher %d is thinking\n",
			get_curr_time() - philo->start, philo);
}

void	action(t_philo *philo)
{
	while (1)
	{	
		if (philo->params->death == 1)
			break ;
		take_forks(philo);
		action_eat(philo);
		release_forks(philo);
		action_sleep(philo);
	}
}	
