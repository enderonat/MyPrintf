/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurasla <egurasla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:02:01 by egurasla          #+#    #+#             */
/*   Updated: 2023/09/05 19:01:56 by egurasla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	char* ilk = (char*)str;
	int c = 0;
	int len = 0;
	while(ilk[c])
	{
		if(ilk[c] != '%')
			len += ft_putchr(ilk[c]);
		else
		{
			c++;
			if(str[c] == '%')
				len += ft_putchr(ilk[c]);
			else if(ilk[c] == 's')
				len += ft_putstr(va_arg(args, char*));
			else if(ilk[c] == 'c')
				len += ft_putchr((unsigned char)va_arg(args, int));
			else if(ilk[c] == 'd' || ilk[c] == 'i')
				len += ft_putnbr(va_arg(args, int));
			else if(ilk[c] == 'u')
				len += ft_putuns(va_arg(args, unsigned int));
			else if(ilk[c] == 'p')
			{
				write (1, "0x", 2);
				len += ft_putpo(va_arg(args, unsigned long));
			}
			else if(ilk[c] == 'x')
				len += ft_x(va_arg(args, unsigned long));
			else if(ilk[c] == 'X')
				len += ft_X(va_arg(args, unsigned long));
		}
		c++;
	}
	va_end(args);
	return(len);
}

int main()
{
	ft_printf("%s", "asdasd");
}