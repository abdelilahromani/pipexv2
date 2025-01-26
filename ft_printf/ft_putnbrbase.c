/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:45:39 by aromani           #+#    #+#             */
/*   Updated: 2025/01/17 14:23:24 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	converter(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr < 16)
		count += ft_putchar(base[nbr]);
	else
	{
		count += converter((nbr / 16), base);
		count += converter((nbr % 16), base);
	}
	return (count);
}

int	ft_putnbrbase(unsigned long nbr, char *base)
{
	int	i;

	ft_putstr("0x");
	i = converter(nbr, base);
	return (i + 2);
}
