/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:44:09 by jiin              #+#    #+#             */
/*   Updated: 2020/01/30 11:11:13 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(char np)
{
	unsigned char	a;
	char			*hex;
	int				num;

	a = (unsigned char)np;
	hex = "0123456789abcdef";
	if (a > 16)
	{
		ft_print_hexa(a / 16);
		ft_print_hexa(a % 16);
	}
	else
	{
		if (a < 10)
			num = a + '0';
		else
			num = (a % 10) + 10;
		ft_putchar(hex[num]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 32 && str[i] >= 0) || str[i] <= 127)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			ft_print_hexa(str[i]);
		}
		else
			ft_putchar(str[i]);
		i += 1;
	}
}
