/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:51:00 by jiin              #+#    #+#             */
/*   Updated: 2020/02/13 19:22:41 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isbase(char c, char *base)
{
	while (*(base) != '\0')
	{
		if (c == *(base))
			return (1);
		base++;
	}
	return (0);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int		ft_isspace(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

int		ft_isvalid_base(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (*(base + i) != '\0')
	{
		j = i + 1;
		while (*(base + j) != '\0')
		{
			if (*(base + j) == *(base + i))
				return (0);
			j++;
		}
		if (*(base + i) == '-' || *(base + i) == '+')
			return (0);
		if (ft_isspace(*(base + i)))
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}
