/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:31:20 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/28 12:02:44 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_chose(char *str, ...)
{
	va_list		args;

	va_start(args, str);

	if (*str == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*str == 'i' || *str == 'd')
		return (ft_putnbr_base("0123456789", va_arg(args, int)));
		else if (*str == 'u')
		return (ft_putnbr_base("0123456789", (long)va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_putnbr_base("0123456789ABCDEF", (long)va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_putnbr_base("0123456789abcdef", (long)va_arg(args, unsigned int)));
	else if (*str == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_putnbr_base("0123456789abcdef", (unsigned long)va_arg(args, void *)));
	}
	else
		return (-1);


}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		j;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			j = 0;
			i++;
			if (str[i] == '%')
			{
				count += ft_putchar(str[i++]);
				continue;
			}
			j = ft_chose((char *)(str + i), (unsigned long)va_arg(args, void *));
			if (j == -1)
			{
				va_end(args);
				return (-1);
			}
			count += j;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	ft_printf("%p\n",  (void *)-14523);
}
