#include "ft_printf.h"
#include <string.h>
#include <stdio.h>

int ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}

void ft_print_base(char *str, long nb, int *j)
{
	if (nb < 0)
	{
		*j += ft_putchar('-');
		ft_print_base(str, nb * -1, j);
	}
	else if (nb < strlen(str))
	*j += ft_putchar(str[nb]);
	else
	{
		ft_print_base(str, nb / strlen(str), j);
		ft_print_base(str, nb % strlen(str), j);
	}
}

int  ft_putnbr_base(char *str, int nbr)
{
	long nb;
	int j;

	j = 0;
	nb = (long)nbr;
	ft_print_base(str, nb,&j);
	return (j);
}

int main()
{
	int i = -2147483648;
	int j;


	j = ft_putnbr_base("0123456789abcdef", i);
	printf("\n%d", j);
}