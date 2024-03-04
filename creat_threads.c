/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:45 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/04 16:12:26 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	philo_eats(t_philo *philo)
{
	t_big	*prg;
	prg = philo->info;
	pthread_mutex_lock(&(prg->forks[philo->fork_left]));
	display_message(philo, "has taken a fork");
	pthread_mutex_lock(&(prg->forks[philo->fork_right]));
	display_message(philo, "has taken a fork");
	display_message(philo, "is eating");
	pthread_mutex_lock(&(prg->eat));
	philo->time_of_last_meal = clock_now();
	pthread_mutex_unlock(&(prg->eat));
	pthread_mutex_lock(&(prg->meal_number));
	philo->meal_number++;
	pthread_mutex_unlock(&(prg->meal_number));
	usleep(prg->time_to_eat * 1000);
	pthread_mutex_unlock(&(prg->forks[philo->fork_left]));
	pthread_mutex_unlock(&(prg->forks[philo->fork_right]));
}


void	*routttinee(void *param)
{
	t_philo		*philo;
	t_big	*prg;
	philo = (t_philo *)param;
	prg = philo->info;
	if (philo->philo_id % 2 == 0)
		sleep(1/2);
	while (1)
	{
		pthread_mutex_lock(&prg->die);
		if (prg->flag_dead == 1)
		{
			pthread_mutex_unlock(&prg->die);
			break ;
		}
		pthread_mutex_unlock(&prg->die);
        if (prg->thread_num == 1)
	    {
		    display_message(prg->thread, "has taken a fork");
            break ;
	    }
	    pthread_mutex_lock(&(prg->all_eat));
	    if (prg->is_all_eaten)
	    {
		    pthread_mutex_unlock(&(prg->all_eat));
		  	break ;
	    }
	    pthread_mutex_unlock(&(prg->all_eat));
		philo_eats(philo);
		display_message(philo, "is sleeping");
		usleep(prg->time_to_sleep * 1000);
		display_message(philo, "is thinking");

	}
	return (NULL);
}


void	update_time_last_meal_for_any_one(t_philo *philo, t_big *prg, int i)
{
	pthread_mutex_lock(&(prg->eat));
	philo[i].time_of_last_meal = clock_now();
	pthread_mutex_unlock(&(prg->eat));
}


void	ft_creat_threads(t_big *prg)
{
	t_philo	*phi;
	int		i;

	i = -1;
	phi = prg->thread;
	prg->start_prg = clock_now();
	while (++i < prg->thread_num)
	{
		pthread_create(&(phi[i].thread_philo), NULL, \
		routttinee, &(phi[i]));
		update_time_last_meal_for_any_one( phi , prg, i);
	}
}
