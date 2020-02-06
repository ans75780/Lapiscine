/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:08:05 by jiin              #+#    #+#             */
/*   Updated: 2020/02/05 21:38:26 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

#include <unistd.h>

typedef int			t_bool;

# define TRUE		1
# define FALSE		0
# define EVEN(x)		((x % 2) == 0 ? TRUE : FALSE)
# define EVEN_MSG 	"I have an even number of arguments.\n"
# define ODD_MSG 	"I have an odd number of arguments.\n"
# define SUCCESS 	0

void				ft_putstr(char *str);
t_bool				ft_is_even(int nbr);

#endif
