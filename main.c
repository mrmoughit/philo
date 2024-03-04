/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:52 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/04 17:20:43 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_is_digits(char *str)
{
    int i = 0;
    long s = ft_atoi(str);
    while (str[i])
    {
        while((str[i] && str[i] == 32 )|| (str[i] <= 13 && str[i] >= 9))
            i++;
        if (str[i] == '+')
            i++;
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 0;
    }
    if (s > 2147483647)
        return 0;
    return 1;
}


void    free_all(t_big *p)
{
    int i;

    i = 0;
    while(i++ < p->thread_num)
        pthread_join(p->thread[i].thread_philo , NULL);
    // i = 0;
    // while (i++ < p->thread_num)
    //     pthread_mutex_destroy(&(p->forks[i]));
    // pthread_mutex_destroy(&(p->print_message));
    // pthread_mutex_destroy(&(p->eat));
    // pthread_mutex_destroy(&(p->die));
    // pthread_mutex_destroy(&(p->all_eat));
    // pthread_mutex_destroy(&(p->meal_number));
    free (p->thread);
    free (p->forks);
}

t_philo	*init_philosopher(t_big *prg)
{
	int	i;
	i = 0;
	t_philo *p;
	t_philo *link;
	p = NULL;
	while(i < prg->thread_num)
	{
		ft_add_back(&p);
		i++;
	}
	i = 0;
	link = p;
	while(p)
	{
		p->fork_right = (i + 2) % prg->thread_num;
		p->meal_number = 0;
		p->info = prg;
		p->time_of_last_meal = 0;
		p->philo_id = i + 1;
		p->fork_left = i + 1;
		i++;
		p = p->next;
	}
	return (link);
}

void	init_infos(t_big *prg, char **av)
{
	prg->thread_num = ft_atoi(av[1]);
	prg->time_to_die = ft_atoi(av[2]);
	prg->time_to_eat = ft_atoi(av[3]);
	prg->time_to_sleep = ft_atoi(av[4]);
	prg->is_all_eaten = 0;
	prg->flag_dead = 0;
	if (av[5])
		prg->time_must_eat = ft_atoi(av[5]);
	else
		prg->time_must_eat = -1;
}

int main (int ac , char **av)
{
    t_big   p;
	t_philo *linked;
    (void)ac;
    (void)av;
    // if (ac != 6 || ac != 5)
    //     return (1);
	ft_parsing(ac ,av , &p);
    ft_set_mutex(&p);
    linked = init_philosopher(&p);
    ft_creat_threads(linked , &p);
    ft_is_die(&p, linked);
    // free_all(&p);
    return 0;
}
