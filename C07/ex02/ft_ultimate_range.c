/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:08:58 by jiin              #+#    #+#             */
/*   Updated: 2020/02/04 13:25:45 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int *numary;
	int i;

	size = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	else
	{
		numary = (int *)malloc(sizeof(int) * size);
		i = 0;
		while (i < size)
		{
			numary[i] = min + i;
			i++;
		}
	}
	*range = numary;
	return (i);
}
