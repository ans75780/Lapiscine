/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:34:18 by jiin              #+#    #+#             */
/*   Updated: 2020/02/09 21:41:55 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"
#include "../includes/dictionary.h"
#include "../includes/ft_str.h"
#include "../includes/ft_trans.h"

char	**ft_put_char_inarr(int argc, char *argv[], char **numary, int col)
{
	int i;
	int row;

	i = 0;
	row = 0;
	while (argv[argc - 1][i] != '\0')
	{
		numary[row][col] = argv[argc - 1][i];
		if (col == 2)
		{
			numary[row][3] = '\0';
			row++;
			col = -1;
		}
		col++;
		i++;
	}
	numary[row] = 0;
	return (numary);
}

char	**ft_put_arr(int argc, char *argv[])
{
	char	**numary;
	int		col;

	numary = ft_malloc_arr(argc, argv);
	if (ft_length(argc, argv) % 3 == 1)
	{
		numary[0][0] = '0';
		numary[0][1] = '0';
		col = 2;
	}
	if (ft_length(argc, argv) % 3 == 2)
	{
		numary[0][0] = '0';
		col = 1;
	}
	if (ft_length(argc, argv) % 3 == 0)
		col = 0;
	ft_put_char_inarr(argc, argv, numary, col);
	return (numary);
}

void	ft_free(char **numarr)
{
	int n;

	n = 0;
	while (g_dic[n].str != 0)
	{
		free(g_dic[n].str);
		free(g_dic[n].key);
		free(g_dic[n].value);
		n++;
	}
	free(g_dic);
	n = 0;
	while (numarr[n] != 0)
	{
		free(numarr[n]);
		n++;
	}
	free(numarr);
}

int		is_argc_one(int argc, char *buf)
{
	int		i;

	if (argc == 1)
	{
		i = 0;
		while (buf[i] != '\0')
			write(1, &buf[i++], 1);
		return (1);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	char	**numarr;
	char	*dic_name;
	char	buf[1000];

	if (ft_check_arg(argc, argv))
		return (ft_error());
	numarr = ft_put_arr(argc, argv);
	dic_name = NULL;
	if (argc == 1 || argc == 2)
		dic_name = "numbers.dict";
	else if (argc == 3)
		dic_name = argv[1];
	if (!ft_make_dic(dic_name, buf))
		return (-1);
	if (is_argc_one(argc, buf))
		return (0);
	if (!ft_trans(numarr, g_size))
		ft_dicerr();
	ft_free(numarr);
	return (0);
}
