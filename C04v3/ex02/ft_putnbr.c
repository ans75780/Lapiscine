/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 08:34:05 by jiin              #+#    #+#             */
/*   Updated: 2020/02/03 19:28:32 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_is_plus(int nb)
{
	int num;

	num = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			num = -147483648;
		}
		num = -1 * num;
	}
	else
		num = nb;
	return (num);
}

void	ft_putnbr(int nb)
{
	int		num;
	int		dev;
	char	mod;
	char	char_dev;

	num = ft_is_plus(nb);
	dev = num / 10;
	mod = num % 10 + '0';
	if (num < 10)
		write(1, &mod, 1);
	else
	{
		if (dev < 10)
		{
			char_dev = dev + '0';
			write(1, &char_dev, 1);
			write(1, &mod, 1);
		}
		if (dev >= 10)
		{
			ft_putnbr(dev);
			write(1, &mod, 1);
		}
	}
}
