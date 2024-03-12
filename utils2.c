/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:52:26 by natamazy          #+#    #+#             */
/*   Updated: 2024/01/25 18:19:21 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 10)
		i = ft_putnbr(nbr / 10);
	i++;
	ft_putchar((nbr % 10) + '0');
	return (i);
}

int	hex_low(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 15)
		i = hex_low(nbr / 16);
	i++;
	ft_putchar("0123456789abcdef"[nbr % 16]);
	return (i);
}

int	hex_up(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 15)
		i = hex_up(nbr / 16);
	i++;
	ft_putchar("0123456789ABCDEF"[nbr % 16]);
	return (i);
}

int	define_print(char n, va_list args)
{
	int				count;
	unsigned long	nbr;

	count = 0;
	if (n == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (n == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (n == 'p')
	{
		nbr = (unsigned long)(va_arg(args, void *));
		write (1, "0x", 2);
		count = ft_print_pointer(nbr);
	}
	else if (n == 'd' || n == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (n == 'u')
		count = ft_putnbr_u(va_arg(args, unsigned int));
	else if (n == 'x')
		count = hex_low(va_arg(args, unsigned int));
	else if (n == 'X')
		count = hex_up(va_arg(args, unsigned int));
	else
		count = write (1, &n, 1);
	return (count);
}
