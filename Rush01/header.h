/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:06:41 by nkang             #+#    #+#             */
/*   Updated: 2020/02/02 19:14:38 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

char			g_arr[5][5];
char			g_cons[4][5];
int				g_flag;

extern void		ft_chk_arr(void);
extern void		ft_put_arr(int depth, char ***pool);
extern void		ft_main(void);
extern int		ft_input(char **argv);
extern void		ft_print_arr(char g_arr[][5]);
extern void		ft_strrcpy(char *dest, char *src, int start, int end);
extern char		**ft_split(char *str);
extern char		**ft_get_case(int lt, int rt);
extern int		ft_is_valid(char *str_row, int size, char lt, char rt);
#endif
