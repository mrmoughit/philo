/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:52 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/05 13:31:07 by abechcha         ###   ########.fr       */
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

void    free_all(t_philo *p)
{
    t_philo *s;
    s = p;
    while(p)
    {
        pthread_join(p->thread_philo , NULL);
        p = p->next;
    }
    p = s;
    int i = 0;
    while(i < p->info->thread_num)
    {
        pthread_mutex_destroy(&(p->info->forks[i]));
        i++;
    }
    pthread_mutex_destroy(&(p->info->print_message));
    pthread_mutex_destroy(&(p->info->eat));
    pthread_mutex_destroy(&(p->info->die));
    pthread_mutex_destroy(&(p->info->all_eat));
    pthread_mutex_destroy(&(p->info->meal_number));
    free (p->info->forks);
    ft_free_linked_list(&s);
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
        if(!p->next)
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

int ft_check_errors(int ac , char **av , t_big *p)
{
    if (ac != 6 && ac != 5)
    {
        ft_error("invalid number of argument");
        return (1);
    }
	if (!ft_parsing(ac ,av , p))
    {
        ft_error("invalid input:example 4 310 80 90");
        return 1;
    }
    if (!ft_set_mutex(p))
    {
        ft_error("init mutex fail");
        return 1;
    }
    return 0;
}

void ff(void)
{
    system("leaks philo");
}
int main (int ac , char **av)
{
    // atexit(ff);
    t_big   p;
	t_philo *linked;

    if (ft_check_errors(ac, av , &p))
        return 1;
    linked = init_philosopher(&p);
    ft_creat_threads(linked , &p);
    ft_is_die(&p, linked);
    free_all(linked);
    return 0;
}
