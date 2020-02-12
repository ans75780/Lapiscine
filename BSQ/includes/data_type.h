/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:20:17 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 16:24:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H
# include "macro.h"

typedef struct	s_map_config
{
	int			num_row;
	int			num_col;
	int			num_col_first;
	char		empty_char;
	char		obstacle_char;
	char		full_char;
}				t_map_con;

typedef struct	s_array
{
	int			array[MAX_LEN];
	int			array_size;
	int			diagonal;
	int			max_num;
}				t_array;

typedef struct	s_result
{
	int			max_num;
	int			max_num_tmp;
	int			res_row;
	int			res_col;
}				t_res_po;

typedef struct	s_map_argument
{
	t_map_con	*map;
	t_array		*arr;
	t_res_po	*res;
}				t_map_argu;

#endif
