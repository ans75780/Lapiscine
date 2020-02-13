/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:35:10 by kylee             #+#    #+#             */
/*   Updated: 2020/02/02 19:24:21 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		g_arr[5][5];
char		g_cons[4][5];
int			g_flag;

void		ft_chk_arr(void)
{
	int		i;
	int		j;
	char	*str_col;

	str_col = malloc(7 * sizeof(char));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			str_col[j] = g_arr[j][i];
			j++;
		}
		str_col[j] = '\0';
		if (!ft_is_valid(str_col, 4, g_cons[0][i], g_cons[1][i]))
		{
			return ;
		}
		i++;
	}
	ft_print_arr(g_arr);
	return ;
}

void		ft_put_arr(int depth, char ***pool)
{
	int		j;

	j = 0;
	if (depth == 4)
	{
		ft_chk_arr();
		return ;
	}
	while (pool[depth][j] != NULL)
	{
		ft_strrcpy(g_arr[depth], pool[depth][j], 0, 3);
		ft_put_arr(depth + 1, pool);
		j++;
	}
	return ;
}

void		ft_main(void)
{
	char	**pool[4];
	int		i;

	i = 0;
	while (i < 4)
	{
		pool[i] = ft_get_case(g_cons[2][i] - '0', g_cons[3][i] - '0');
		i++;
	}
	ft_put_arr(0, pool);
	if (!g_flag)
		write(1, "Error\n", 6);
	return ;
}

int			ft_input(char **argv)
{
	int		i;
	int		col;
	int		row;

	i = 0;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (argv[1][i] < '0' || argv[1][i] > '4')
			{
				write(1, "Error\n", 6);
				return (0);
			}
			g_cons[row][col] = argv[1][i];
			col++;
			i += 2;
		}
		row++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_input(argv))
			ft_main();
	}
	else
		write(1, "Error\n", 6);
}
