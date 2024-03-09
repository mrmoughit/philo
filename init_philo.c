/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:15:45 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 13:20:09 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philosopher(t_big *prg)
{
	int		i;
	t_philo	*p;
	t_philo	*link;

	i = 0;
	p = NULL;
	while (i++ < prg->thread_num)
		ft_add_back(&p);
	i = 0;
	link = p;
	while (p)
	{
		if (!p->next)
			p->fork_right = 0;
		else
			p->fork_right = i + 1;
		p->meal_number = 0;
		p->info = prg;
		p->time_of_last_meal = clock_now();
		p->philo_id = i + 1;
		p->fork_left = i;
		i++;
		p = p->next;
	}
	return (link);
}
