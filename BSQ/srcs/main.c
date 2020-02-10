/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:43:56 by jiin              #+#    #+#             */
/*   Updated: 2020/02/10 22:29:43 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_io.h"
#include "data_type.h"
#include "macro.h"
#include "ft_math.h"
#include <stdio.h>
#include <stdlib.h>
//#include <fildes.h>

/*
** desc: 지도 행 길이 반환 함수
** params: fd
** return: length of one row.
*/



/*
** desc: 지도 행 길이 반환 함수
** params: fd
** return: length of one row.
*/
int		ft_lenght_row(int fd)
{
	char	buf;
	int		length;

	buf = 0;
	read(fd, &buf, 1);
	length = 0;
	while (buf != '\n' || buf != '\0')
	{
		read(fd, &buf, 1);
		length++;
	}
	return (length);
}


int     ft_min_arr(t_array *arr, int i)
{
	int	temp;

    if (i == 0)
	{
		arr->array[i] = ft_min(arr->array[i], arr->diagonal);
	}
    else
    {
        temp = arr->array[i];
        arr->array[i] = ft_min(ft_min(arr->array[i], arr->array[i - 1]), arr->diagonal);
        arr->diagonal = temp;
    }
    return (arr->array[i]);
}

/*
** desc: 장애물 유무를 확인해서 숫자로 표현하는 함수
** params:
** return:
*/

void   	ft_set_num(char *buf, t_map_config *map, t_array *arr)
{
    int i;

    i = 0;
    arr->diagonal = 0;   

    while (i < map->num_col)
    {
        if (buf[i] == 'o')//map->obstacle_char)
            arr->array[i]= 0;
		else if (buf[i] == '.')//map->empty_char)
            arr->array[i] = ft_min_arr(arr, i) + 1;
        else
        {
            ft_write("Error\n");
            exit(0);
        }
		printf("%d", arr->array[i]);
        i++;
    }
	printf("\n");
    if (!(buf[i] == '\n' || buf[i] == '\0'))
    {
        ft_write("sdfsd Error\n");
        exit(0);
    }
}

/*
** desc: 메인 함수
** params:
** return:
*/

void	ft_init(t_array *arr)
{
	int i;

	i = 0;
	while (i< MAX_LEN)
	{
		arr->array[i] = 0;
		i++;
	}
}

int main(int argc, char *argv[])
{
	int fd;
	char *map_name;
	char buf[MAX_LEN];
	t_map_config	map;
	t_array			arr;

	ft_init(&arr);
	map.num_col = 0;
	if (argc == 1)
	{
		fd = open("map", O_RDONLY);
	}   
	if (argc == 2)
	{
		map_name = argv[1];
		fd = open(map_name, O_RDONLY);
	}
	if (fd < 0)
	{
		ft_write("Map Error\n");
		return (-1);
	}


	read(fd, buf, 5);
	map.num_row = buf[0] -'0';
    ft_write(buf);
    read(fd, buf, MAX_LEN);
    while (buf[map.num_col] != '\n' && buf[map.num_col])
        map.num_col++;
    printf("%d\n", map.num_col);
	fd = open(map_name, O_RDONLY);
	read(fd, buf, 5);
	buf[5] = '\0';
    int i;
	i = 0;
    while (i < map.num_row)
    {
		// 한 줄 읽으면서 그 전 최솟값 + 1 or 장애물이면 0
		// 해당 값이 기존 저장한 값의 최대라면, 해당 위치의 인덱스와 값으로 교쳊
        read(fd, buf, map.num_col + 1);
		buf[map.num_col] = '\0';
        ft_set_num(buf, &map, &arr); // 문자열 채우는 용도 
		i++;
    }

	close(fd);
	return (0);
}
