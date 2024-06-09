/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:30:52 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/06/09 17:43:31 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	char_count;

	char_count = write(1, &c, 1);
	return (char_count);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long n, int base, char is_upper)
{
	int		counter;
	char	*base_chars;
	char	*cap_base_chars;

	base_chars = "0123456789abcdef";
	cap_base_chars = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n, base, is_upper) + 1);
	}
	else if (n < base && is_upper != 'X')
		return (ft_putchar(base_chars[n]));
	else if (n < base && is_upper == 'X')
		return (ft_putchar(cap_base_chars[n]));
	else
	{
		counter = ft_putnbr(n / base, base, is_upper);
		return (counter + ft_putnbr(n % base, base, is_upper));
	}
}

int	ft_pointer(void *ptr)
{
	int			length;
	uintptr_t	helper;

	helper = (uintptr_t)ptr;
	ft_putchar('0');
	ft_putchar('x');
	length = ft_putnbr(helper, 16, 'x');
	length = length + 2;
	return (length);
}
