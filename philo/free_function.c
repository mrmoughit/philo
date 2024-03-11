/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:14:45 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 13:20:37 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_linked_list(t_philo **stack)
{
	t_philo	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free((*stack));
		*stack = temp;
	}
	*stack = NULL;
}

void	free_all(t_philo *p)
{
	t_philo	*s;
	int		i;

	s = p;
	while (p)
	{
		pthread_join(p->thread_philo, NULL);
		p = p->next;
	}
	p = s;
	i = 0;
	while (i < p->info->thread_num)
	{
		pthread_mutex_destroy(&(p->info->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(p->info->print_message));
	pthread_mutex_destroy(&(p->info->eat));
	pthread_mutex_destroy(&(p->info->die));
	pthread_mutex_destroy(&(p->info->all_eat));
	pthread_mutex_destroy(&(p->info->meal_number));
	free(p->info->forks);
	ft_free_linked_list(&s);
}
