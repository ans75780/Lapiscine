/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:27:22 by jiin              #+#    #+#             */
/*   Updated: 2020/02/04 17:55:30 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	long long	i;
	int			is_prime;

	i = 2;
	is_prime = 1;
	while (i * i <= (long long)nb)
	{
		if ((long long)nb % i == 0)
		{
			is_prime = 0;
			break ;
		}
		i++;
	}
	return (is_prime);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	if (nb <= 2)
		return (2);
	while (ft_is_prime(i) != 1)
	{
		i++;
	}
	return (i);
}
