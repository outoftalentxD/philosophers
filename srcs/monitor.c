/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:36:29 by melaena           #+#    #+#             */
/*   Updated: 2021/08/26 20:46:26 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_philo *philo)
{
	int			i;
	t_params	*params;

	params = philo[0].params;
	while (1)
	{
		i = -1;
		while (++i < params->count)
		{
			if (get_curr_time() - philo[i].eat > params->die_time)
			{
				params->death = 1;
				pthread_mutex_lock(params->pmute);
				printf("%ld philosopher %d has died\n",
					get_curr_time() - philo[i].start, philo[i].id);
				return ;
			}
			if (params->count == params->finished)
			{
				params->death = 1;
				return ;
			}
		}
		usleep(1);
	}
}
