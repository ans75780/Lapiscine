/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:44:07 by jiin              #+#    #+#             */
/*   Updated: 2020/02/09 22:21:41 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dictionary.h"
#include "../includes/ft_trans.h"

int		ft_length(int argc, char *argv[])
{
	int len;

	len = 0;
	while (argv[argc - 1][len] != '\0')
		len++;
	return (len);
}

int		ft_check_arg(int argc, char *argv[])
{
	int i;

	if (argc > 3 || argc < 1)
		return (1);
	i = 0;
	if (argc == 1)
		return (0);
	while (argv[argc - 1][i] != '\0')
	{
		if (!((argv[argc - 1][i] >= '0') && (argv[argc - 1][i] <= '9')))
			return (1);
		++i;
	}
	if (i == 0)
		return (1);
	return (0);
}

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		ft_dicerr(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

char	**ft_malloc_arr(int argc, char *argv[])
{
	int		len;
	char	**numary;
	int		row;

	len = ft_length(argc, argv);
	numary = (char**)malloc(sizeof(char*) * (len / 3 + 2));
	row = 0;
	if (len % 3 == 0)
		len = len / 3;
	else
		len = len / 3 + 1;
	while (row < len)
	{
		numary[row] = malloc(1);
		row++;
	}
	return (numary);
}
