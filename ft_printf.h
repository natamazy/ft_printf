/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:36:26 by natamazy          #+#    #+#             */
/*   Updated: 2024/01/25 18:11:50 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_strlen(char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_print_pointer(unsigned long nbr);
int	ft_putnbr(int nbr);
int	ft_putnbr_u(unsigned int nbr);
int	hex_low(unsigned int nbr);
int	hex_up(unsigned int nbr);
int	define_print(char n, va_list args);

#endif
