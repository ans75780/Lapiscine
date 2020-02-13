/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:35:12 by kylee             #+#    #+#             */
/*   Updated: 2020/02/02 19:13:40 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_print_arr(char g_arr[][5])
{
	int		row;
	int		col;

	row = 0;
	while (row < 4 && !g_flag)
	{
		col = 0;
		while (col < 4)
		{
			write(1, &g_arr[row][col], 1);
			if (col != 4 - 1)
				write(1, " ", 1);
			col++;
		}
		row++;
		write(1, "\n", 1);
	}
	g_flag = 1;
}

void		ft_strrcpy(char *dest, char *src, int start, int end)
{
	int		i;

	i = 0;
	while (start <= end)
	{
		*(dest + i) = *(src + start);
		i++;
		start++;
	}
	*(dest + i) = '\0';
	return ;
}

char		**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*str_copy;
	char	**str_arr;

	k = 0;
	j = 0;
	i = 0;
	str_arr = malloc(10 * sizeof(char *));
	str_copy = malloc(5 * sizeof(char));
	while (*(str + i) != '\0')
	{
		if (*(str + i) == ' ')
		{
			ft_strrcpy(str_copy, str, j, i - 1);
			*(str_arr + k++) = str_copy;
			j = i + 1;
			str_copy = malloc(5 * sizeof(char));
		}
		i++;
	}
	free(str_copy);
	*(str_arr + k) = NULL;
	return (str_arr);
}

char		**ft_get_case(int lt, int rt)
{
	char	**pool;

	pool = malloc(7 * sizeof(char *));
	if (lt == 1 && rt == 3)
		pool = ft_split("4132 4231 4312 ");
	else if (lt == 1 && rt == 4)
		pool = ft_split("4321 ");
	else if (lt == 2 && rt == 3)
		pool = ft_split("1432 2431 3421 ");
	else if (lt == 1 && rt == 2)
		pool = ft_split("4123 4213 ");
	else if (lt == 2 && rt == 2)
		pool = ft_split("1423 2143 2413 3142 3241 3412 ");
	else if (lt == 3 && rt == 1)
		pool = ft_split("1324 2134 2314 ");
	else if (lt == 4 && rt == 1)
		pool = ft_split("1234 ");
	else if (lt == 3 && rt == 2)
		pool = ft_split("1243 1342 2341 ");
	else if (lt == 2 && rt == 1)
		pool = ft_split("3124 3214 ");
	else
		*pool = NULL;
	return (pool);
}

int			ft_is_valid(char *str_row, int size, char lt, char rt)
{
	char	**pool;
	int		i;
	int		j;

	pool = ft_get_case(lt - '0', rt - '0');
	j = 0;
	while (pool[j] != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (str_row[i] != pool[j][i])
				break ;
			i++;
		}
		if (i == size)
		{
			free(pool);
			return (1);
		}
		j++;
	}
	free(pool);
	return (0);
}
