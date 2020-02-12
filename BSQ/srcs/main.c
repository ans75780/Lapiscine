/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:43:56 by jiin              #+#    #+#             */
/*   Updated: 2020/02/12 19:23:21 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "data_type.h"
#include "ft_io.h"
#include "ft_setting.h"
#include "ft_print.h"
#include <stdlib.h>

void			ft_main(int fd, char *map_name)
{
	t_map_con	map;
	t_array		arr;
	t_res_po	res;
	t_map_argu	map_argu;
	char		buf[MAX_LEN];

	ft_init_res(&res);
	ft_init_arr(&arr);
	ft_init_map(&map, fd);
	map_argu.arr = &arr;
	map_argu.res = &res;
	map_argu.map = &map;
	fd = open(map_name, O_RDONLY);
	read(fd, buf, map.num_col_first + 1);
	ft_set_map(fd, &map_argu);
	if (g_error)
		ft_write("Error\n");
	else
		ft_print_res(map_name, &res, &map);
	close(fd);
	return ;
}

/*
** desc: 표준 입력으로 받을 때 실행하는 함수
** params:
** return:
*/

void			ft_std_func(void)
{
	char		buf[MAX_LEN_BUF];
	char		*map_name;
	int			fd;

	map_name = TEMP_FILE;
	fd = open(map_name, O_CREAT);
	close(fd);
	fd = open(map_name, O_WRONLY);
	while (read(0, buf, 1))
		write(fd, buf, 1);
	close(fd);
	fd = open(map_name, O_RDONLY);
	ft_write("\n");
	ft_main(fd, map_name);
	return ;
}

/*
** desc: main function calling ft_main
** params: argc, argv
** return: 0 no problems.
*/

int				main(int argc, char *argv[])
{
	int			fd;
	char		*map_name;
	int			j;

	j = 1;
	if (argc == 1)
	{
		ft_std_func();
		return (0);
	}
	while (j < argc)
	{
		g_error = 0;
		map_name = argv[j];
		fd = open(map_name, O_RDONLY);
		ft_main(fd, map_name);
		if (j != argc - 1)
			ft_write("\n");
		j++;
	}
	while (1)
	{
		;
	}
}
