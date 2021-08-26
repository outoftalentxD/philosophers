/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:41:41 by melaena           #+#    #+#             */
/*   Updated: 2021/08/26 22:18:32 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_status("%ld philosopher %d has taken a fork\n",
		get_curr_time() - philo->start, philo);
	pthread_mutex_lock(philo->rfork);
	print_status("%ld philosopher %d has taken a fork\n",
		get_curr_time() - philo->start, philo);
	return (1);
}

int	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (1);
}
