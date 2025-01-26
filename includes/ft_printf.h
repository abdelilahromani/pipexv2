/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:11:38 by aromani           #+#    #+#             */
/*   Updated: 2024/11/25 11:05:32 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printhexa(unsigned int nbr, char *base);
int		ft_putchar(char c);
int		ft_putnbrunsig(unsigned int nbr);
int		ft_putnbr(int n);
int		ft_putnbrbase(unsigned long nbr, char *base);
int		ft_putstr(const char *s);

#endif
