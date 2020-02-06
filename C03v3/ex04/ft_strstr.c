/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 09:47:35 by jiin              #+#    #+#             */
/*   Updated: 2020/02/02 17:12:44 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_same(char *str, char *to_find, int i)
{
	int j;

	j = 0;
	while (to_find[j] != '\0')
	{
		if (str[i] == to_find[j])
		{
			i++;
			j++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	i = 0;
	if (to_find[0] == '\0')
		return (&str[i]);
	while (str[i] != '\0')
	{
		if (str[i] != to_find[0])
			i++;
		else
		{
			if (is_same(str, to_find, i))
				return (&str[i]);
			else
				i++;
		}
	}
	return (0);
}
