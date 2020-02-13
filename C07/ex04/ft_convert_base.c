/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:50:16 by jiin              #+#    #+#             */
/*   Updated: 2020/02/13 19:23:46 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int		ft_isvalid_base(char *base);
extern int		ft_isbase(int c, char *base);

int				ft_base_to_deci(char *num, char *base)
{
	int			ret;
	int			div;
	int			i;

	i = 0;
	ret = 0;
	div = ft_get_size_base(base);
	while (*(num + i) != '\0' && ft_isbase(*(num + i), base))
	{
		ret *= div;
		ret += ft_find_base(*(num + i), base);
		i++;
	}
	return (ret);
}

char			*ft_deci_to_base(int num, char *base)
{
	char		*ret;
	int			len;
	int			temp;
	int			div;

	div = ft_get_size_base(base);
	temp = num;
	len = 0;
	while (temp != 0)
	{
		temp /= div;
		len++;
	}
	ret = (char *)malloc((len + 3) * sizeof(char));
	ret[0] = (num < 0) ? '-' : ret[0];
	ret[0] = (num == 0) ? *(base + 0) : ret[0];
	len = (num <= 0) ? len + 1 : len;
	*(ret + len) = '\0';
	while (num != 0)
	{
		len--;
		*(ret + len) = *(base + ft_abs(num % div));
		num /= div;
	}
	return (ret);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			num;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	if (!ft_isvalid_base(base_from) || !ft_isvalid_base(base_to))
		return (0);
	while (ft_isspace(*(nbr + i)))
		i++;
	while (*(nbr + i) == '+' || *(nbr + i) == '-')
	{
		if (*(nbr + i) == '-')
			sign *= -1;
		i++;
	}
	num = ft_base_to_deci(nbr + i, base_from);
	return (ft_deci_to_base(sign * num, base_to));
}
