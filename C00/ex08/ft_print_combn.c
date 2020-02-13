/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:43:20 by jiin              #+#    #+#             */
/*   Updated: 2020/01/25 15:57:19 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		countfunc(int num)
{
	int		newnum;
	int		count;

	newnum = num;
	count = 1;
	while (newnum >= 10)
	{
		newnum = newnum / 10;
		if (newnum >= 1)
			count++;
	}
	return (count);
}

int		make_new_num(int count)
{
	int		ans;
	int		i;

	i = 0;
	ans = 1;
	while (i <= count)
	{
		ans = 10 * ans;
		i++;
	}
	return (ans);
}

void	ft_print_combn(int n)
{
	int		num;
	int		i;
	int		j;
	char	arr[9];

	num = n;
	i = 0;
	while (i <= make_new_num(num))
	{
		j = num - 1;
		while (j >= 0)
		{
			arr[j] = (i % 10) + '0';
			write(1, &arr[j], 1);
			j--;
		}
		write(1, ", ", 2);
		i++;
	}
}
