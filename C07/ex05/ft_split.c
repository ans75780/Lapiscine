/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:31:30 by jiin              #+#    #+#             */
/*   Updated: 2020/02/13 19:27:34 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int		ft_row_count(char *str, char *charset)
{
	int i;
	int row_count;

	i = 0;
	row_count = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(str[i], charset))
		{
			while (str[i] != '\0' && (!is_charset(str[i], charset)))
				++i;
			++row_count;
		}
		++i;
	}
	return (row_count);
}

void	ft_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
	{
		*(dest++) = *(from++);
	}
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**map;
	int		index;
	int		i;
	int		from;

	index = 0;
	map = (char**)malloc(sizeof(char*) * (ft_row_count(str, charset) + 1));
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(str[i], charset))
		{
			from = i;
			while (str[i] != '\0' && (!is_charset(str[i], charset)))
			{
				++i;
			}
			map[index] = (char*)malloc(sizeof(char) * ((i - from) + 1));
			ft_strcpy(map[index], &str[from], &str[i]);
			++index;
		}
		++i;
	}
	map[index] = 0;
	return (map);
}
