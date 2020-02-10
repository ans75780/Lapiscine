/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:20:17 by kylee             #+#    #+#             */
/*   Updated: 2020/02/10 21:46:42 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_H
# define DATA_TYPE_H
# include "macro.h"

typedef struct  s_map_config
{
	int         num_row;
	int         num_col;
	char        empty_char;
	char        obstacle_char;
	char        full_char;
}               t_map_config;

typedef struct  s_array
{
	int         array[MAX_LEN];
	int         array_size;
	
	int         ans_col;
	int         ans_row;
	int         ans_val;
	int			diagonal;
}               t_array;

#endif