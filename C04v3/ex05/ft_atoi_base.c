/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:10:14 by jiin              #+#    #+#             */
/*   Updated: 2020/02/06 21:36:10 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_size(char *base)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (base[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
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

int		ft_calculate(char *str, char *base, int i, int size)
{
	long long	result;
	int			i2;
	int			j;
	int			count;

	result = 0;
	count = 0;
	i2 = i;
	while (str[i2] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i2] == base[j])
			{
				result = (result + j) * size;
				count++;
				break ;
			}
			j++;
		}
		if (count != (++i2 - i))
			break ;
	}
	return (result / size);
}

int		ft_atoi_base(char *str, char *base)
{
	int				i;
	int				sign;
	long long		result;
	int				size;

	if (!is_valid(base))
		return (0);
	i = 0;
	while ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
		return (0);
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	size = ft_size(base);
	result = ft_calculate(str, base, i, size) * sign;
	return ((int)result);
}
