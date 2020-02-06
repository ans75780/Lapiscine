/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:53:09 by jiin              #+#    #+#             */
/*   Updated: 2020/02/06 21:07:35 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*s_av;
	int 			i;
	int				j;

	s_av = malloc(sizeof(t_stock_str) * (ac + 1));
	(s_av + ac)->str = NULL;
	i = 0;
	while (i < ac)
	{
		(s_av + i)->size = ft_strlen(*(av + i));
		(s_av + i)->str = *(av + i);
		(s_av + i)->copy = malloc(sizeof(char) * ((s_av + i)->size + 1)); 
		j = 0;
		while (j < (s_av + i)->size)
		{
			(s_av+i)->copy[j] = *(*(av + i) + j);
			j++;
		}
		(s_av + i)->copy[j] = '\0';
		i++;
	}
	return (s_av);
}
