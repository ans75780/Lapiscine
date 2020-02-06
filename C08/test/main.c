/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:52:43 by jiin              #+#    #+#             */
/*   Updated: 2020/02/06 21:09:36 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	t_stock_str *list;
	list = ft_strs_to_tab(argc, argv);


	for(int i=0; i<3; i++)
	{
		ft_show_tab(list);
//		printf("%d\n",list[i].size);
//		printf("%s\n",list[i].str);
//		printf("%s\n",list[i].copy);
	}

	return (0);
}
