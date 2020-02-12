/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:47:15 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 16:25:38 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "ft_math.h"
#include "ft_valid.h"
#include "ft_utils.h"

/*
** desc: 왼쪽, 왼쪽 대각선, 위의 값을 확인해서 최소값을 찾아주는 함수
** params:
** return:
*/

int				ft_min_arr(t_array *arr, int i)
{
	int			temp;

	if (i == 0)
	{
		temp = arr->array[i];
		arr->array[i] = ft_min(arr->array[i], arr->diagonal);
		arr->diagonal = temp;
		return (0);
	}
	else
	{
		temp = arr->array[i];
		arr->array[i] = ft_min(arr->array[i], arr->array[i - 1]);
		arr->array[i] = ft_min(arr->array[i], arr->diagonal);
		arr->diagonal = temp;
	}
	return (arr->array[i]);
}

int				ft_set_num(char *buf, t_map_argu *map_argu, int row)
{
	int			i;

	i = -1;
	map_argu->arr->diagonal = 0;
	while (++i < map_argu->map->num_col)
	{
		if (buf[i] == map_argu->map->obstacle_char)
			map_argu->arr->array[i] = 0;
		else if (buf[i] == map_argu->map->empty_char)
			map_argu->arr->array[i] = ft_min_arr(map_argu->arr, i) + 1;
		else
			return (ft_g_error());
		if (map_argu->arr->array[i] > map_argu->res->max_num)
		{
			map_argu->res->max_num = map_argu->arr->array[i];
			map_argu->res->res_row = row;
			map_argu->res->res_col = i;
		}
	}
	if (!(buf[i] == '\n' || buf[i] == '\0'))
		return (ft_g_error());
	return (0);
}

void			ft_get_char(char *buf, t_map_con *map, t_res_po *res, int row)
{
	int			i;

	i = 0;
	while (i < map->num_col)
	{
		if (buf[i] == map->obstacle_char)
			ft_write_c(map->obstacle_char);
		else if (ft_is_box(res, i, row))
			ft_write_c(map->full_char);
		else
			ft_write_c(map->empty_char);
		i++;
	}
	ft_write("\n");
	return ;
}

void			ft_print_res(char *map_name, t_res_po *res, t_map_con *map)
{
	int			fd;
	char		buf[MAX_LEN];
	int			i;

	fd = open(map_name, O_RDONLY);
	read(fd, buf, map->num_col_first + 1);
	i = 0;
	while (i < map->num_row)
	{
		read(fd, buf, map->num_col + 1);
		buf[map->num_col] = '\0';
		ft_get_char(buf, map, res, i);
		i++;
	}
	close(fd);
}
