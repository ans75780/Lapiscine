/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:29:02 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 14:16:35 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_valid.h"
#include "macro.h"
#include <stdio.h>

extern int		g_error;

int				ft_min(int num1, int num2)
{
	return ((num1 > num2) ? num2 : num1);
}

int				ft_atoi_n(char *str, int n)
{
	int			sum;
	int			i;

	i = 0;
	sum = 0;
	while (*str && i < n)
	{
		if (!(ft_is_numeric(*str)))
		{
			g_error++;
			return (-1);
		}
		sum = (sum * 10) + *(str) - '0';
		str++;
		i++;
	}
	return (sum);
}

int				ft_is_same(char a, char b, char c)
{
	if (a != b)
	{
		if (a != c && b != c)
			return (0);
	}
	return (1);
}
