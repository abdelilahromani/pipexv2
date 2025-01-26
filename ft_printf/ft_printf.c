/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:36:46 by aromani           #+#    #+#             */
/*   Updated: 2025/01/17 14:23:09 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_checker(const char *format, va_list str)
{
	int	len;

	len = 0;
	if (*format == 'd' || *format == 'i')
		len += ft_putnbr(va_arg(str, int));
	else if (*format == 'u')
		len += ft_putnbrunsig(va_arg(str, int));
	else if (*format == 'c')
		len += ft_putchar((char)va_arg(str, int));
	else if (*format == 's')
		len += ft_putstr((const char *)va_arg(str, char *));
	else if (*format == 'p')
		len += ft_putnbrbase((unsigned long)va_arg(str, void *),
				"0123456789abcdef");
	else if (*format == 'x')
		len += ft_printhexa((unsigned int)va_arg(str, void *),
				"0123456789abcdef");
	else if (*format == 'X')
		len += ft_printhexa((unsigned int)va_arg(str, void *),
				"0123456789ABCDEF");
	else if (*format == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(*format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(str, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			len += ft_checker(&format[i], str);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(str);
	return (len);
}
