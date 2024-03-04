/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:09:45 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/04 14:35:59 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int  ft_parsing(int ac ,char **av, t_big *p)
{
    int i = 1;
    while(i <= ac - 1)
    {
        if(!ft_is_digits(av[i]))
            return 0;
        i++;
    }
    p->is_all_eaten = 0;
    p->flag_dead = 0;
    p->thread_num = ft_atoi(av[1]);
    p->time_to_die = ft_atoi(av[2]);
    p->time_to_eat = ft_atoi(av[3]);
    p->time_to_sleep = ft_atoi(av[4]);
    if (ac == 5)
        p->time_must_eat = -1;
    else
        p->time_must_eat = ft_atoi(av[5]);
    if (!p->thread_num || !p->time_to_die || !p->time_to_eat || !p->time_to_sleep || !p->time_must_eat)
        return 0;
    return 1;
}