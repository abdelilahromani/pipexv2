/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:50:36 by aromani           #+#    #+#             */
/*   Updated: 2025/01/17 14:23:14 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printhexa(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr < 16)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_printhexa((nbr / 16), base);
		count += ft_printhexa((nbr % 16), base);
	}
	return (count);
}
