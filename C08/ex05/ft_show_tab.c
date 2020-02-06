#include "ft_stock_str.h"
#include <unistd.h>

void	ft_get_int(int div, int mod)
{
	mod = div % 10;
	div = div / 10;
	if (div != 0)
		ft_get_int(div, mod);
	write(1, (mod + '0'), 1);
}

void ft_show_tab(struct s_stock_str *par)
{
	int i;
	
	i = 0;
	while ((par + i)->str != NULL)
	{
		write(1, (par + i)->str, (par + i)->size);
		write(1, "\n", 1);

		ft_get_int((par+i)->size, 0);
		write(1, "\n", 1);

		write(1, (par + i)->copy, (par + i)->size);
		write(1, "\n", 1);
		i++;
	}
	return;
}
