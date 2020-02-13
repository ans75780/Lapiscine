/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:17:00 by jiin              #+#    #+#             */
/*   Updated: 2020/01/30 09:19:33 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		dev;
	char	mod;
	char	char_dev;

	dev = nb / 10;
	mod = nb % 10 + '0';
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
