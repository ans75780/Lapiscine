/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:50:15 by kylee             #+#    #+#             */
/*   Updated: 2020/02/12 16:21:00 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SETTING_H
# define FT_SETTING_H

void			ft_init_arr(t_array *arr);
void			ft_init_res(t_res_po *res);
void			ft_init_map(t_map_con *map, int fd);
void			ft_set_map(int fd, t_map_argu *map_argu);

#endif
