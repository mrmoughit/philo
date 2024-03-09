/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:45 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 16:46:30 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_eat(t_philo *philo)
{
	t_big	*prg;

	prg = philo->info;
	pthread_mutex_lock(&(prg->forks[philo->fork_left]));
	display_message(philo, "has taken a fork");
	pthread_mutex_lock(&(prg->forks[philo->fork_right]));
	display_message(philo, "has taken a fork");
	pthread_mutex_lock(&(prg->eat));
	display_message(philo, "is eating");
	philo->time_of_last_meal = clock_now();
	pthread_mutex_unlock(&(prg->eat));
	pthread_mutex_lock(&(prg->meal_number));
	philo->meal_number++;
	pthread_mutex_unlock(&(prg->meal_number));
	my_usleep(prg->time_to_eat);
	pthread_mutex_unlock(&(prg->forks[philo->fork_left]));
	pthread_mutex_unlock(&(prg->forks[philo->fork_right]));
}

int	part_one(t_big *prg, t_philo *philo)
{
	pthread_mutex_lock(&prg->die);
	if (prg->flag_dead == 1)
	{
		pthread_mutex_unlock(&prg->die);
		return (0);
	}
	pthread_mutex_unlock(&prg->die);
	if (prg->thread_num == 1)
	{
		display_message(philo, "has taken a fork");
		return (0);
	}
	pthread_mutex_lock(&(prg->all_eat));
	if (prg->is_all_eaten)
	{
		pthread_mutex_unlock(&(prg->all_eat));
		return (0);
	}
	pthread_mutex_unlock(&(prg->all_eat));
	return (1);
}

void	part_two(t_big *prg, t_philo *philo)
{
	ft_is_eat(philo);
	display_message(philo, "is sleeping");
	my_usleep(prg->time_to_sleep);
	display_message(philo, "is thinking");
}

void	*thread_life_circle(void *param)
{
	t_big	*prg;
	t_philo	*philo;

	philo = (t_philo *)param;
	prg = philo->info;
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (!part_one(prg, philo))
			break ;
		part_two(prg, philo);
	}
	return (NULL);
}

void	ft_creat_threads(t_philo *p, t_big *big)
{
	t_philo	*current_philo;

	current_philo = p;
	big->start_prg = clock_now();
	while (current_philo != NULL)
	{
		pthread_create(&(current_philo->thread_philo), NULL, thread_life_circle,
			current_philo);
		pthread_mutex_lock(&(big->eat));
		current_philo->time_of_last_meal = clock_now();
		pthread_mutex_unlock(&(big->eat));
		current_philo = current_philo->next;
	}
}
