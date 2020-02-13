/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:46:52 by jiin              #+#    #+#             */
/*   Updated: 2020/02/13 21:25:02 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*newsrc;
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (src[i] != '\0')
		size++;
	newsrc = (char *)malloc(sizeof(char) * (size + 1));
	if (!newsrc)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		newsrc[i] = src[i];
		i++;
	}
	newsrc[i] = '\0';
	return (newsrc);
}
