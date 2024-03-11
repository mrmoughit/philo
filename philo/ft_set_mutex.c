/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:56:16 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 08:52:19 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_mutex(t_big *p)
{
	int	i;

	i = -1;
	p->forks = malloc(sizeof(pthread_mutex_t) * p->thread_num);
	if (!(p->forks))
		return (0);
	while (++i < p->thread_num)
		if (pthread_mutex_init(&(p->forks[i]), NULL))
			return (0);
	if (pthread_mutex_init(&(p->print_message), NULL))
		return (0);
	if (pthread_mutex_init(&(p->eat), NULL))
		return (0);
	if (pthread_mutex_init(&(p->die), NULL))
		return (0);
	if (pthread_mutex_init(&(p->all_eat), NULL))
		return (0);
	if (pthread_mutex_init(&(p->meal_number), NULL))
		return (0);
	return (1);
}
