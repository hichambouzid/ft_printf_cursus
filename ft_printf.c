/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:31:20 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/29 14:38:31 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_chose(char *str, ...)
{
	va_list	args;
	int		j;

	j = 0;
	va_start(args, str);
	if (*str == 'c')
		j += ft_putchar((char)va_arg(args, int));
	else if (*str == 's')
		j += ft_putstr(va_arg(args, char *));
	else if (*str == 'p')
	{
		j += ft_putstr("0x");
		ft_print_base("0123456789abcdef", (unsigned long)va_arg(args, void *),
			&j);
	}
	else if (*str == 'd' || *str == 'i' || *str == 'd')
		ft_putnbr((long)va_arg(args, int), &j);
	else if (*str == 'u')
		ft_print_base("0123456789", (unsigned int)va_arg(args, int), &j);
	else if (*str == 'x')
		ft_print_base("0123456789abcdef", (unsigned int)va_arg(args, int), &j);
	else if (*str == 'X')
		ft_print_base("0123456789ABCDEF", (unsigned int)va_arg(args, int), &j);
	return (j);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_check(char *tab, char c)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		j;

	va_start(args, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && !ft_check("cspdiuxX%", str[i + 1]))
			return (-1);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				count += ft_putchar(str[i++]);
				continue ;
			}
			j = ft_chose((char *)(str + i), (unsigned long)va_arg(args,
						void *));
			if (j == -1)
			{
				va_end(args);
				return (-1);
			}
			count += j;
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(args);
	return (count);
}
