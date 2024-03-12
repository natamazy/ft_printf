/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:39:50 by natamazy          #+#    #+#             */
/*   Updated: 2024/01/25 18:07:35 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	ft_print_pointer(unsigned long nbr)
{
	int	len;

	len = 2;
	if (nbr > 15)
		len = ft_print_pointer(nbr / 16);
	len++;
	ft_putchar("0123456789abcdef"[nbr % 16]);
	return (len);
}

int	ft_putnbr(int nbr)
{
	int				i;
	int				j;
	unsigned int	nb1;

	i = 0;
	j = 0;
	if (nbr < 0)
	{
		j = ft_putchar('-');
		nbr = -nbr;
	}
	nb1 = (unsigned int) nbr;
	if (nb1 >= 10)
		i = ft_putnbr(nb1 / 10);
	i++;
	ft_putchar(nb1 % 10 + '0');
	return (i + j);
}
