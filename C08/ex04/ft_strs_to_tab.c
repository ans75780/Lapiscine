/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:53:09 by jiin              #+#    #+#             */
/*   Updated: 2020/02/06 14:13:22 by jiin             ###   ########.fr       */
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

struct s_stock_atr *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*s_av;
	int 			i;
	int				j;

	s_av = malloc(sizeof(t_stock_atr) * ac);
	(s_av + ac)->str = NULL;
	i = 0;
	while (i < ac)
	{
		(s_av + i)->size = ft_strlen(*(av + i));
		(s_av + i)->str = *(av + i);
		j = 0;
		while (j < (s_av + i)->size)
		{
			(s_av+i)->copy[j] = *(*(av + i) + j);
			j++;
		}
		(s_av + i)->copy[i] = '\0';
		i++;
	}
//	free(s_av);
	return (s_av);
//배열의 크기 출력인데...s_av맞나..? 게다가 free(s_av)하고나서는 안될것 같은데!
}
int main(int ac, char **av)
{
	typedef struct  s_stock_str
	{
	    int size;
	    char *str;
	    char *copy;
	}               t_stock_str;

	ft_strs_to_tab(ac, av);
}
