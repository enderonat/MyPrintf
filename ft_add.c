/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurasla <egurasla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:02:04 by egurasla          #+#    #+#             */
/*   Updated: 2023/09/05 17:18:29 by egurasla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return(1);
}

int ft_putstr(char *s)
{
	size_t i = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while(s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return(i);
}

int ft_putnbr_recursive(int n, int l)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return l + 11;
	}

	if (n < 0)
	{
		n *= -1;
		ft_putchr('-');
		l++;
	}

	if (n > 9)
	{
		l = ft_putnbr_recursive(n / 10, l);
		l = ft_putnbr_recursive(n % 10, l);
	}
	else
	{
		l++;
		ft_putchr(n + 48);
	}

	return l;
}

int ft_putnbr(int n)
{
	int l = 0;
	l = ft_putnbr_recursive(n, l);
	return (l);
}

size_t ft_putuns_recursive(unsigned int n, size_t *i)
{
	if (n > 9)
	{
		ft_putuns_recursive(n / 10, i);
		ft_putuns_recursive(n % 10, i);
	}
	else
	{
		ft_putchr(n + 48);
		(*i)++;
	}
	return(0);
}

size_t ft_putuns(unsigned int n)
{
	size_t i = 0;
	ft_putuns_recursive(n, &i);
	return i;
}

size_t	ft_putpo_recursive(unsigned long nbr, unsigned long *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		if (nbr < 10)
			ft_putchr(nbr + '0');
		else
			ft_putchr(base[nbr % 16]);
		(*i)++;
	}
	if (nbr >= 16)
	{
		ft_putpo_recursive(nbr / 16, i);
		ft_putpo_recursive(nbr % 16, i);
	}
	return(0);
}

size_t	ft_putpo(unsigned long nbr)
{
	size_t i = 0;
	ft_putpo_recursive(nbr, &i);
	return i+2;
}

int ft_X_recursive(unsigned int nbr, unsigned long *i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr < 16)
	{
		if (nbr < 10)
			ft_putchr(nbr + '0');
		else
			ft_putchr(base[nbr % 16]);
		(*i)++;
	}
	if (nbr >= 16)
	{
		ft_X_recursive(nbr / 16, i);
		ft_X_recursive(nbr % 16, i);
	}
	return (0);
}
int	ft_X(unsigned int nbr)
{
	size_t i = 0;
	ft_X_recursive(nbr, &i);
	return (i);
}

int ft_x_recursive(unsigned int nbr, unsigned long *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		if (nbr < 10)
			ft_putchr(nbr + '0');
		else
			ft_putchr(base[nbr % 16]);
		(*i)++;
	}
	if (nbr >= 16)
	{
		ft_x_recursive(nbr / 16, i);
		ft_x_recursive(nbr % 16, i);
	}
	return (0);
}
int	ft_x(unsigned int nbr)
{
	size_t i = 0;
	ft_x_recursive(nbr, &i);
	return (i);
}