/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:08:36 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 14:07:27 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "data_type.h"

void		ft_write(const char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	return ;
}

void		ft_write_c(char c)
{
	write(1, &c, 1);
	return ;
}
