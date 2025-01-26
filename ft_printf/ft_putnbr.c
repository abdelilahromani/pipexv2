/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:34:50 by aromani           #+#    #+#             */
/*   Updated: 2025/01/17 14:23:21 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar ('-');
		count += ft_putchar ('2');
		count += ft_putnbr (147483648);
	}
	else if (n < 0)
	{
		n *= -1;
		count += ft_putchar ('-');
		count += ft_putnbr (n);
	}
	else if (n > 9)
	{
		count += ft_putnbr (n / 10);
		count += ft_putnbr (n % 10);
	}
	else
	{
		count += ft_putchar (n + 48);
	}
	return (count);
}
