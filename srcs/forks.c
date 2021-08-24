/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:41:41 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 19:43:48 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int waiter_mutex_lock(t_philo *philo, int id, int opt)
{
	philo->params->waiter[id] = 1;
	if (opt == 'l')
		pthread_mutex_lock(philo->lfork);
	else if (opt == 'r')
		pthread_mutex_lock(philo->rfork);
	return (1);
}

int waiter_mutex_unlock(t_philo *philo, int id, int opt)
{
	philo->params->waiter[id] = 0;
	if (opt == 'l')
		pthread_mutex_unlock(philo->lfork);
	else if (opt == 'r')
		pthread_mutex_unlock(philo->rfork);
	return (1);
}


int take_forks(t_philo *philo)
{
	int idleft;
	int idright;
	long int time;

	idleft = philo->id - 1;
	idright = (philo->id != philo->params->count - 1) * philo->id;
	if (philo->params->waiter[idleft] == 0)
	{
		if (philo->params->waiter[idright] == 0)
		{
			waiter_mutex_lock(philo, idleft, 'l');
			waiter_mutex_lock(philo, idright, 'r');
		}
		else
			return(0);
	}
	else
		return (0);
	return (1);
}

int release_forks(t_philo *philo)
{
	int idleft;
	int idright;

	idleft = philo->id - 1;
	idright = (philo->id != philo->params->count - 1) * philo->id;
	waiter_mutex_unlock(philo, idleft, 'l');
	waiter_mutex_unlock(philo, idright, 'r');
	return (1);
}
