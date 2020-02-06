#include <stdio.h>

int	*ft_range(int main, int max);

int   main(void)
{
	int* res;
	int i;

	res = ft_range(5, 10);

	for (i = 0; i < 5; i++)
	  printf("%d,", res[i]);
	printf("\n");

	res = ft_range(-20, -15);
	for (i = 0; i < 5; i++)
	  printf("%d,", res[i]);
	printf("\n");

	res = ft_range(-2147483648, -2147483646);
	for (i = 0; i < 1; i++)
		printf("%d,", res[i]);
	printf("\n");

	res = ft_range(10, 5);
	printf("%x\n", (unsigned int)res);
}
