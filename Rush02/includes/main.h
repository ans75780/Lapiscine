/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:46:55 by jiin              #+#    #+#             */
/*   Updated: 2020/02/09 16:37:42 by jinkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

int		ft_length(int argc, char *argv[]);
int		ft_check_arg(int argc, char *argv[]);
int		ft_error(void);
int		ft_dicerr(void);
char	**ft_malloc_arr(int argc, char *argv[]);
char	**ft_put_char_inarr(int argc, char *argv[], char **numary, int col);
char	**ft_put_arr(int argc, char *argv[]);
void	ft_free(char **numarr);
int		is_argc_one(int argc, char *buf);

#endif
