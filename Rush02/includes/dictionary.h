/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:40:05 by jinkim            #+#    #+#             */
/*   Updated: 2020/02/09 15:26:25 by jinkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_dictionary
{
	char *str;
	char *key;
	char *value;
}				t_dic;
t_dic			*g_dic;
int				g_size;
int				ft_make_dic(char *dic_name, char *buf);
#endif
