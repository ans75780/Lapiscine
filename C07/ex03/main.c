#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
	int i;
	char *strs[4] = {"abc", "sdf", "ert"};
	char *sep = "z";

	i = 0;
	printf("%s", ft_strjoin(3, strs, sep));
	return (0);
}
