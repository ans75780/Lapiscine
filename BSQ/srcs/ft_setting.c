/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:41:45 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 16:25:19 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_type.h"
#include "ft_math.h"
#include "ft_valid.h"
#include "ft_print.h"
#include <unistd.h>

void			ft_init_arr(t_array *arr)
{
	int			i;

	i = 0;
	while (i < MAX_LEN)
	{
		arr->array[i] = 0;
		i++;
	}
	arr->array_size = 0;
	arr->diagonal = 0;
	arr->max_num = 0;
}

void			ft_init_res(t_res_po *res)
{
	res->max_num = 0;
	res->res_col = 0;
	res->res_row = 0;
	res->max_num_tmp = 0;
}

void			ft_init_map(t_map_con *map, int fd)
{
	int			i;
	char		buf[MAX_LEN_COL];

	i = 0;
	read(fd, buf, MAX_LEN_COL);
	while (buf[i] != '\n')
		i++;
	map->num_col = 0;
	map->num_col_first = i;
	map->num_row = ft_atoi_n(buf, i - 3);
	map->obstacle_char = buf[i - 2];
	map->empty_char = buf[i - 3];
	map->full_char = buf[i - 1];
	if (i < 4 || ft_is_same(buf[i - 3], buf[i - 2], buf[i - 1]))
	{
		g_error++;
		close(fd);
	}
	ft_is_printable(buf[i - 2]);
	ft_is_printable(buf[i - 3]);
	i++;
	while (buf[i + map->num_col] != '\n' && buf[i + map->num_col] != '\0')
		map->num_col++;
	close(fd);
}

void			ft_set_map(int fd, t_map_argu *map_argu)
{
	int			i;
	char		buf[MAX_LEN_BUF];

	i = 0;
	while (i < map_argu->map->num_row)
	{
		read(fd, buf, map_argu->map->num_col + 1);
		buf[map_argu->map->num_col] = '\0';
		map_argu->res->max_num_tmp = map_argu->res->max_num;
		if (ft_set_num(buf, map_argu, i))
			return ;
		if (map_argu->res->max_num_tmp != map_argu->res->max_num)
			map_argu->res->res_row = i;
		i++;
	}
}
