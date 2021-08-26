/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melaena <melaena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 20:04:48 by melaena           #+#    #+#             */
/*   Updated: 2021/08/26 20:17:10 by melaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char str)
{
	if (str == '\t'
		|| str == '\n'
		|| str == '\r'
		|| str == '\f'
		|| str == '\v'
		|| str == ' ')
		return (1);
	else
		return (0);
}

static int	ft_isnumeric(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

static int	ft_sign(int num)
{
	if (num < 0)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int		count;
	int		num;
	int		neg;

	count = 0;
	num = 0;
	neg = 1;
	while (ft_isspace(str[count]))
		count++;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			neg = -1;
		else
			neg = 1;
		count++;
	}
	while (ft_isnumeric(str[count]))
	{
		if (num * 10 < num)
			return (ft_sign(neg));
		num *= 10;
		num += str[count++] - '0';
	}
	return (num * neg);
}
