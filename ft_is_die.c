/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:07:19 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/04 12:07:45 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	ft_is_die(t_big *prg, t_philo *philo)
{
	int	i;
	while (!(prg->is_all_eaten))
	{

	i = -1;
	while (++i < prg->thread_num && !(prg->flag_dead))
	{
		pthread_mutex_lock(&prg->eat);
		if ((clock_now() - philo[i].time_of_last_meal) >= prg->time_to_die)
		{
			display_message(philo, "died");
			pthread_mutex_lock(&(prg->die));
			prg->flag_dead = 1;
			pthread_mutex_unlock(&(prg->die));
		}
		pthread_mutex_unlock(&prg->eat);
		usleep(100);
	}
	if (prg->flag_dead == 1)
		break ;
	i = 0;
	pthread_mutex_lock(&(prg->meal_number));
	while (prg->time_must_eat != -1
		&& i < prg->thread_num
		&& philo[i].meal_number >= prg->time_must_eat)
		i++;
	pthread_mutex_unlock(&(prg->meal_number));
	if (i == prg->thread_num)
	{
		pthread_mutex_lock(&(prg->all_eat));
		prg->is_all_eaten = 1;
		pthread_mutex_unlock(&(prg->all_eat));
	}
	pthread_mutex_unlock(&(prg->all_eat));
	}
}
