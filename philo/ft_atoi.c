/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:39 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 13:21:42 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(char *str)
{
	int		i;
	int		sing;
	long	nb;
	long	r;

	i = 0;
	sing = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = nb;
		nb = nb * 10 + str[i] - 48;
		if (r != nb / 10)
			ft_error("overflow");
		i++;
	}
	return (nb * sing);
}
