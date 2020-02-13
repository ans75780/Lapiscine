/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:23:08 by jiin              #+#    #+#             */
/*   Updated: 2020/01/25 21:48:21 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		front;
	int		end;
	char	num[4];

	front = 0;
	while (front <= 98)
	{
		end = front + 1;
		while (end <= 99)
		{
			num[0] = '0' + front / 10;
			num[1] = '0' + front % 10;
			num[2] = '0' + end / 10;
			num[3] = '0' + end % 10;
			write(1, &num, 2);
			write(1, " ", 1);
			write(1, &num[2], 2);
			if (front < 98)
				write(1, ", ", 2);
			end++;
		}
		front++;
	}
}
