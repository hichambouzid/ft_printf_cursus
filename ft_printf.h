/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:56:09 by hibouzid          #+#    #+#             */
/*   Updated: 2023/11/28 11:30:53 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<stdarg.h>
#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>

int ft_printf(const char *str, ...);
int	ft_chose(char *str, ...);
int ft_putchar(char c);
int ft_putstr(char *str);
int ft_strlen(char *str);
int  ft_putnbr_base(char *str, long long nbr);

#endif
