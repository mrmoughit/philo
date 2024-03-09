/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:52 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 13:19:48 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_digits(char *str)
{
	int		i;
	long	s;

	i = 0;
	s = ft_atoi(str);
	while (str[i])
	{
		while ((str[i] && str[i] == 32) || (str[i] <= 13 && str[i] >= 9))
			i++;
		if (str[i] == '+')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (s > 2147483647)
		return (0);
	return (1);
}

int	ft_check_errors(int ac, char **av, t_big *p)
{
	if (ac != 6 && ac != 5)
	{
		ft_error("invalid number of argument");
		return (1);
	}
	if (!ft_parsing(ac, av, p))
	{
		ft_error("invalid input:example 4 310 80 90");
		return (1);
	}
	if (!ft_set_mutex(p))
	{
		ft_error("init mutex fail");
		return (1);
	}
	return (0);
}

void	ff(void)
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	t_big	p;
	t_philo	*linked;

	if (ft_check_errors(ac, av, &p))
		return (1);
	linked = init_philosopher(&p);
	ft_creat_threads(linked, &p);
	ft_is_die(&p, linked);
	free_all(linked);
	return (0);
}
