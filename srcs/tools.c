/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 04:18:39 by melaena           #+#    #+#             */
/*   Updated: 2021/08/24 14:10:02 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int args_is_valid(char **av)
{
	while (*(++av))
		if (!is_number(*av))
			throw_error(ARG_ERROR);
	return (1);
}

int is_number(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

void throw_error(int code)
{
	char *error;

	if (code == ARGS_COUNT_ERROR)
		error = "[i] ERROR: Wrong number of arguments\n";
	else if (code == ARG_ERROR)
		error = "[i] ERROR: Wrong argument\n";
	else if (code == ALLOC_ERORR)
		error = "[i] ERROR: Memory allocation error\n";
	write(2, error, ft_strlen(error));
	exit(0);
}

long int	get_curr_time(void)
{
	struct timeval	now;
	long int		time;

	gettimeofday(&now, NULL);
	time = now.tv_sec * 100 + now.tv_usec / 1000;
	return (time);
}