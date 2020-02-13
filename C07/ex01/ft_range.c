/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:23:54 by jiin              #+#    #+#             */
/*   Updated: 2020/02/13 18:52:16 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int size;
	int *numary;
	int i;

	size = max - min;
	if (min >= max)
		return (NULL);
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
	return (numary);
}
