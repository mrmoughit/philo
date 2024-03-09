/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:58 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/09 15:57:21 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_big	*info;
	struct s_philo	*next;
	int				philo_id;
	long long		time_of_last_meal;
	pthread_t		thread_philo;
	int				fork_left;
	int				fork_right;
	int				meal_number;
}					t_philo;

typedef struct s_big
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				is_all_eaten;
	int				flag_dead;
	long long		start_prg;
	t_philo			*thread;
	int				thread_num;

	pthread_mutex_t	eat;
	pthread_mutex_t	die;
	pthread_mutex_t	all_eat;
	pthread_mutex_t	meal_number;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_message;
}					t_big;

int					ft_parsing(int ac, char **av, t_big *p);
int					ft_set_mutex(t_big *p);
int					ft_is_digits(char *str);
void				ft_add_back(t_philo **head);
void				ft_free_linked_list(t_philo **stack);
void				free_all(t_philo *p);
void				ft_error(char *str);
void				my_usleep(long long time);
long				ft_atoi(char *str);
void				display_message(t_philo *p, char *s);
void				ft_is_die(t_big *prg, t_philo *philo);
void				ft_creat_threads(t_philo *p, t_big *big);
t_philo				*ft_lstnew(void);
t_philo				*init_philosopher(t_big *prg);
long long			clock_now(void);
#endif
