/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:35:56 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 15:49:12 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "data_type.h"

int				ft_is_box(t_res_po *res, int col, int row)
{
	if (col <= res->res_col && col > res->res_col - (res->max_num))
	{
		if (row <= res->res_row && row > res->res_row - (res->max_num))
			return (1);
	}
	return (0);
}

int				ft_g_error(void)
{
	g_error++;
	return (-1);
}
