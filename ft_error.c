/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:27:27 by abechcha          #+#    #+#             */
/*   Updated: 2024/03/04 12:14:41 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *s)
{
    if (!s)
        return 0;
    int i = 0;
    while(s[i])
        i++;
    return i;
}
void ft_error(char *str)
{
    write(2, "Error\n", 6);
    write(2, str ,ft_strlen(str));
    write(2, "\n", 1);
}