/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egurasla <egurasla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:01:57 by egurasla          #+#    #+#             */
/*   Updated: 2023/09/05 17:18:51 by egurasla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int	ft_putchr(char c);
int ft_putstr(char *s);
size_t  ft_strlen(const char *s);
size_t ft_putuns_recursive(unsigned int n, size_t *i);
size_t	ft_putuns(unsigned int n);
size_t  ft_putpo_recursive(unsigned long nbr, unsigned long *i);
size_t	ft_putpo(unsigned long nbr);
int ft_x(unsigned int nbr);
int ft_X_recursive(unsigned int nbr, unsigned long *i);
int ft_X(unsigned int nbr);
int ft_putnbr_recursive(int n, int l);
int ft_putnbr(int n);

#endif