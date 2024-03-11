/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:47:05 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 15:47:33 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(long long time)
{
	long long	time_now;

	time_now = clock_now();
	while (clock_now() - time_now < time)
		usleep(10);
}
