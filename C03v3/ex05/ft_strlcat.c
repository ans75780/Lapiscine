/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:03:05 by jiin              #+#    #+#             */
/*   Updated: 2020/01/30 17:04:27 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_count;
	unsigned int src_count;
	unsigned int result;

	dest_count = 0;
	while (dest[dest_count] != '\0')
		dest_count++;
	src_count = 0;
	dest[dest_count] = '\0';
	while (src[src_count] != '\0')
		src_count++;
	if (size >= dest_count)
		result = src_count + dest_count;
	else
		result = src_count + size;
	src_count = 0;
	while (src[src_count] != '\0' && dest_count + 1 < size)
	{
		dest[dest_count] = src[src_count];
		dest_count++;
		src_count++;
	}
	dest[dest_count] = '\0';
	return (result);
}
