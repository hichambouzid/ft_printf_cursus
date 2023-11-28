/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:08:13 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/28 16:00:13 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_base(char *str, unsigned long nb, int *j)
{

	if (nb >= (unsigned long)ft_strlen(str))
	{
		ft_print_base(str, nb / ft_strlen(str), j);
		ft_print_base(str, nb % ft_strlen(str), j);
	}
	else
		*j += ft_putchar(str[nb]);
}


void ft_putnbr(long nbr, int *count)
{
	if (nbr < 0)
	{
		*count += ft_putchar('-');
		ft_putnbr(nbr * -1,  count);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else
		*count += ft_putchar(nbr + 48);
}
