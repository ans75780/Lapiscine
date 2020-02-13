/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:31:25 by jinkim            #+#    #+#             */
/*   Updated: 2020/01/25 21:38:28 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_if(int r, int c, int x, int y)
{
	if (((r == 0) && (c == 0)) || ((r == x - 1) && (c == 0)))
	{
		ft_putchar('A');
	}
	else if (((r == 0) && (c == y - 1)) || ((r == x - 1) && (c == y - 1)))
	{
		ft_putchar('C');
	}
	else if (((r != 0) && (c != 0)) && ((r != x - 1) && (c != y - 1)))
	{
		ft_putchar(' ');
	}
	else
	{
		ft_putchar('B');
	}
}

void	rush(int x, int y)
{
	int	r;
	int c;

	c = 0;
	while (c < y)
	{
		r = 0;
		while (r < x)
		{
			ft_if(r, c, x, y);
			r++;
		}
		ft_putchar('\n');
		c++;
	}
}
