/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:34:03 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/26 15:53:17 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(const char *str);
int	ft_hextoa(unsigned int num);
int	ft_hextoa_upper(unsigned int num);
int	ft_pointtoa(unsigned long long num);
int	ft_conv(char c, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putcharc(char c);
int	ft_putnbr_signed(int n, int count);
int	ft_putnbr_unsigned(unsigned int n, int count);
int	ft_putstr(const char *str);

#endif
