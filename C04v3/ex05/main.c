/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjo <jjo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:28:20 by jjo               #+#    #+#             */
/*   Updated: 2020/02/06 21:36:23 by jiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ft_atoi_base(char *str, char *base);

int main()
{
	printf("MY ANSWER\n");
	printf("%d\n", ft_atoi_base("abc314d","abcde  "));
	printf("%d\n", ft_atoi_base("   12abc", "Abc12"));
//	printf("%d\n", ft_atoi_base("f111fkjsdjfkjsd", "f1"));
//	printf("%d\n", ft_atoi_base("-+--2321fkjsdjfkjsd", "0123456789"));
//	printf("%d\n", ft_atoi_base("++++--2147483647","0123456789"));
//	printf("%d\n", ft_atoi_base("---2147483648","0123456789"));
//	printf("%d\n", ft_atoi_base("2321f213213kjsdjfkjsd","0123456788"));
//	printf("%d\n\n", ft_atoi_base("00000111111111kjsdjfkjsd","0123456789"));

//	printf("ANSWER\n");
//	printf("%d\n", 14);
//	printf("%d\n", -2321);
//	printf("%d\n", +2147483647);
//	printf("%ld\n", -2147483648);
//	printf("%d\n", 0);
//	printf("%d\n", 111111111);
	return (0);
}
