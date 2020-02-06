/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:11:21 by jiin              #+#    #+#             */
/*   Updated: 2020/02/06 21:27:32 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int j;
	int index;
	char *string_ary;
	int len_size;
	char *point;

	i = 0;
	while (strs[i] != '\0')
	{
		j = 0;
		while (*strs[j] != '\0')
		{
			len_size++;
			j++;
		}
		i++;
	}
	
	string_ary = (char*)malloc(sizeof(char)*(len_size + size));
	point = string_ary;
	i = 0;
	index = 0;
	while (strs[i] != '\0')
	{
		j = 0;
		while (*strs[j] != '\0')
		{
			string_ary[index] = *strs[j];
			j++;
			index++;
		}
		while (*sep != '\0')
		{
			string_ary[index] = *sep;
			index++;
			sep++;
			i++;
		}
	}
	return (point);
}
