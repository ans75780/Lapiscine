/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:58:30 by sayi              #+#    #+#             */
/*   Updated: 2020/02/09 15:04:35 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRANS_H
# define FT_TRANS_H

int		ft_trans(char **num, int size);
int		ft_trans_hund(char *num, char *dest);
int		ft_trans_ten(char *num, char *dest, char *tmp);
int		ft_row_unit(int row_index, char *dest);
int		num_max_index(char **num);
void	ft_print(char *word_arr);
int		is_zero_row(char *num);
int		ft_num_mat_dic(char *num, char *dest);

#endif
