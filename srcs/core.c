/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:36:29 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 15:55:25 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_forks(t_philo *philo)
{
	
}

void action(t_philo *philo)
{
	static int count;
	
	while (1)
	{
		philo->meals_count++;
		printf("Philo [%d] eated %d times!\n", philo->id, philo->meals_count);
	}
}	

