/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:56:09 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/28 15:54:10 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_chose(char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putnbr(long nbr, int *count);
void	ft_print_base(char *str, unsigned long nb, int *j);

#endif
