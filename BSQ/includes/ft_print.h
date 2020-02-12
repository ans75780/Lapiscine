/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:53:44 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 16:20:45 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "data_type.h"
# include "ft_io.h"
# include <fcntl.h>

void			ft_print_res(char *map_name, t_res_po *res, t_map_con *map);
void			ft_get_char(char *buf, t_map_con *map, t_res_po *res, int row);
int				ft_set_num(char *buf, t_map_argu *map_argu, int row);
int				ft_min_arr(t_array *arr, int i);
#endif
