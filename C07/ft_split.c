/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:50:26 by jiin              #+#    #+#             */
/*   Updated: 2020/02/06 19:54:19 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *str, int size)
{
	int i;
	char *str_copy;

	str_copy = malloc(sizeof(char) * size);
	i = 0;
	while (str[i])
	{
		str_copy[i + 1] = str[i];
		i++;
	}
	str_copy[0] = '\0';
	str_copy[i] = '\0';
	return (str_copy);
}

char	*ft_change_str(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				str[i] = '\0';
			j++;
		}
		i++;
	}
	return (str);
}

int		ft_str_size(char *str)
{
	int i;

	 i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int i;
	int j;
	int str_size;
	int w_count;
	char **res;
	char *str_copy;

	str_size = ft_str_size(str) + 1;
	str_copy = ft_strcpy(str, str_size);
	str_copy = ft_change_str(str_copy, charset);


	i = 1;
	w_count = 0;
	while (i < str_size)
	{
		if (str_copy[i - 1] != '\0'  && str_copy[i] == '\0')
			w_count++;
		i++;
	}

	res = (char**)malloc(sizeof(char*) * w_count);

	i = 0;
	j = 0;
	while (i < str_size)
	{
		if (str_copy[i] == '\0' && str_copy[i + 1] != '\0')
		{
			*(res + j) = (str_copy + i);
			j++;
		}
		i++;
	}
	return (res);
}

#include <stdio.h>
int main()
{
	int i;
//	char **res;
//	res = ft_split("helloworld", "od");

	printf("%d\n", ft_str_size("abc"));
	printf("%s\n", ft_strcpy("abc", 4));
//	printf("%s", *(res));
//	printf("%s", *(res + 1));

}
