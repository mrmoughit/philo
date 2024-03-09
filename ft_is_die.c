/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:07:19 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 13:24:35 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_is_die(t_big *prg, t_philo *philo)
{
	t_philo	*s;

	s = philo;
	while (!(prg->is_all_eaten) && !(prg->flag_dead))
	{
		while (philo && !(prg->flag_dead))
		{
			pthread_mutex_lock(&prg->eat);
			if ((clock_now() - philo->time_of_last_meal) > prg->time_to_die)
			{
				display_message(philo, "died");
				pthread_mutex_lock(&(prg->die));
				prg->flag_dead = 1;
				pthread_mutex_unlock(&(prg->die));
			}
			pthread_mutex_unlock(&prg->eat);
			philo = philo->next;
		}
		if (prg->flag_dead == 1)
			break ;
		philo = s;
		pthread_mutex_lock(&(prg->meal_number));
		while (philo && prg->time_must_eat != -1
			&& philo->meal_number >= prg->time_must_eat)
			philo = philo->next;
		pthread_mutex_unlock(&(prg->meal_number));
		if (!philo)
		{
			pthread_mutex_lock(&(prg->all_eat));
			prg->is_all_eaten = 1;
			pthread_mutex_unlock(&(prg->all_eat));
		}
	}
}
