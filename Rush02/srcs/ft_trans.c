/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:45:22 by sayi              #+#    #+#             */
/*   Updated: 2020/02/09 22:35:46 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dictionary.h"
#include "../includes/ft_str.h"
#include "../includes/ft_trans.h"

int		ft_trans(char **num, int size)
{
	int		i;
	char	*word_arr;

	word_arr = (char *)malloc(size * 3);
	i = 0;
	while (num[i])
	{
		if (is_zero_row(num[i]) && (i++) + 1)
			continue ;
		if (!ft_trans_hund(num[i], word_arr))
			return (0);
		if (!ft_row_unit(num_max_index(num) - i, word_arr))
			return (0);
		i++;
	}
	if (!ft_strlen(word_arr))
		ft_num_mat_dic(&num[i - 1][2], word_arr);
	ft_print(word_arr);
	return (1);
}

int		ft_trans_hund(char *num, char *dest)
{
	char	tmp[3];

	tmp[0] = num[0];
	tmp[1] = '\0';
	tmp[2] = '\0';
	if (num[0] > '0')
	{
		if (!ft_num_mat_dic(&tmp[0], dest))
			return (0);
		if (!ft_num_mat_dic("100", dest))
			return (0);
	}
	if (!ft_trans_ten(num, dest, tmp))
		return (0);
	return (1);
}

int		ft_trans_ten(char *num, char *dest, char *tmp)
{
	tmp[0] = num[1];
	if (num[1] > '1')
	{
		tmp[1] = '0';
		if (!ft_num_mat_dic(tmp, dest))
			return (0);
	}
	else if (num[1] == '1')
	{
		tmp[1] = num[2];
		if (!ft_num_mat_dic(tmp, dest))
			return (0);
		return (1);
	}
	if (num[2] > '0')
		if (!ft_num_mat_dic(&num[2], dest))
			return (0);
	return (1);
}

int		ft_row_unit(int row_index, char *dest)
{
	int		i;
	char	*unit;

	unit = malloc(sizeof(char) * ((row_index * 3) + 2));
	unit[0] = '1';
	i = 1;
	while (i < row_index * 3 + 1)
	{
		unit[i] = '0';
		i++;
	}
	unit[i] = '\0';
	if (unit[1] && !ft_num_mat_dic(unit, dest))
	{
		free(unit);
		return (0);
	}
	free(unit);
	return (1);
}
