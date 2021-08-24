/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:36:29 by melaena           #+#    #+#             */
/*   Updated: 2021/08/25 00:29:43 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void monitor(t_philo *philo)
{
	long int time;

	time = get_curr_time() - philo->eat;
	if (time > philo->params->die_time);
	
}

