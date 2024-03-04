/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:06:07 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/04 15:51:54 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(void)
{
	t_philo	*p;
	p = (t_philo *)malloc(sizeof(t_philo));
	if (!p)
		return (NULL);
    p->next = NULL;
	return (p);
}

void ft_add_back(t_philo **head)
{
    t_philo *p;
    p = *head;
    if (p == NULL)
        *head = ft_lstnew(); 
    else
    {
        while(p->next)
            p = p->next;
        p->next = ft_lstnew();
    }
}