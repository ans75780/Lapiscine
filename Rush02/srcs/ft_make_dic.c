/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_dic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:14:05 by jinkim            #+#    #+#             */
/*   Updated: 2020/02/09 21:59:29 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dictionary.h"

int		ft_dic_open(char *dic_name, char *buf)
{
	int fd;

	fd = open(dic_name, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	read(fd, buf, 1000);
	return (fd);
}

void	ft_dic_alloc(int num_key)
{
	int i;

	g_dic = malloc(sizeof(t_dic) * num_key);
	i = 0;
	while (i < num_key)
	{
		g_dic[i].str = (char *)malloc(sizeof(char) * g_size);
		g_dic[i].key = (char *)malloc(sizeof(char) * g_size);
		g_dic[i].value = (char *)malloc(sizeof(char) * g_size);
		i++;
	}
}

void	ft_make_str(char *buf)
{
	int i;
	int d;
	int idx;

	i = 0;
	d = 0;
	idx = 0;
	while (i < g_size)
	{
		if (buf[i] == '\n')
		{
			g_dic[d++].str[idx] = '\0';
			idx = 0;
			i++;
			if (buf[i] == '\0')
				break ;
		}
		while (buf[i] != '\n')
		{
			g_dic[d].str[idx] = buf[i];
			idx++;
			i++;
		}
	}
	g_dic[d].str = 0;
}

void	ft_key_value(int num_key, int d, int str, int check_key)
{
	int key;
	int value;

	while (d < num_key)
	{
		check_key = 0;
		key = 0;
		value = 0;
		str = -1;
		while (g_dic[d].str[++str] != '\0')
		{
			if (g_dic[d].str[str] == ':')
			{
				g_dic[d].key[key] = '\0';
				while (g_dic[d].str[str] != ' ')
					str++;
				check_key = 1;
			}
			else if (check_key == 0 && g_dic[d].str[str] != ' ')
				g_dic[d].key[key++] = g_dic[d].str[str];
			else if (check_key == 1)
				g_dic[d].value[value++] = g_dic[d].str[str];
		}
		g_dic[d++].value[value] = '\0';
	}
}

int		ft_make_dic(char *dic_name, char *buf)
{
	int		i;
	int		fd;
	int		num_key;

	fd = ft_dic_open(dic_name, buf);
	if (fd == -1)
		return (0);
	g_size = 0;
	while (buf[g_size] != '\0')
		g_size++;
	i = 0;
	num_key = 0;
	while (i < g_size)
	{
		if (buf[i] == '\n')
			num_key++;
		i++;
	}
	ft_dic_alloc(num_key);
	ft_make_str(buf);
	close(fd);
	ft_key_value(num_key, 0, 0, 0);
	return (1);
}
