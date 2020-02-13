/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:27:47 by sayi              #+#    #+#             */
/*   Updated: 2020/02/09 16:07:21 by jinkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dictionary.h"
#include "../includes/ft_str.h"
#include "../includes/ft_trans.h"

int		num_max_index(char **num)
{
	int	i;

	i = 0;
	while (num[i])
		i++;
	return (i - 1);
}

void	ft_print(char *word_arr)
{
	word_arr[ft_strlen(word_arr) - 1] = '\n';
	write(1, word_arr, ft_strlen(word_arr));
	free(word_arr);
}

int		is_zero_row(char *num)
{
	if (num[0] == '0' && num[1] == '0' && num[2] == '0')
		return (1);
	return (0);
}

int		ft_num_mat_dic(char *num, char *dest)
{
	int	i;

	i = 0;
	while (g_dic[i].str)
	{
		if (!ft_strcmp(g_dic[i].key, num))
		{
			ft_strcat(dest, g_dic[i].value);
			return (1);
		}
		i++;
	}
	return (0);
}
