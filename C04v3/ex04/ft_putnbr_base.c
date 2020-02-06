/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 21:39:42 by jiin              #+#    #+#             */
/*   Updated: 2020/02/04 18:06:45 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_size(char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int		is_valid(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (i < ft_size(base) - 1)
	{
		j = i + 1;
		while (j < ft_size(base))
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < ft_size(base))
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	loop(int div, int mod, char *base, int size)
{
	mod = div % size;
	div = div / size;
	if (div != 0)
		loop(div, mod, base, size);
	write(1, &base[mod], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				size;
	long long		num;

	size = ft_size(base);
	if (!is_valid(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = (long long)nbr * -1;
	}
	else
		num = (long long)nbr;
	loop(num, 0, base, size);
}
