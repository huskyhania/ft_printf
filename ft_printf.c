/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:27:28 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/06/12 21:02:58 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_choice(char specifier, va_list arguments)
{
	int		count;
	char	*base_chars;

	count = 0;
	base_chars = "0123456789abcdef";
	if (specifier == 'c')
		count = ft_putchar(va_arg(arguments, int));
	else if (specifier == 's')
		count = ft_putstr(va_arg(arguments, char *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr(va_arg(arguments, int), 10, specifier);
	else if (specifier == 'u')
		count = ft_putnbr(va_arg(arguments, unsigned int), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		count = ft_putnbr(va_arg(arguments, unsigned int), 16, specifier);
	else if (specifier == 'p')
		count = ft_pointer(va_arg(arguments, void *), 0, 0, base_chars);
	else
		count = ft_putchar(specifier);
	return (count);
}

static int	helper(const char *s, va_list arguments, int count, int total)
{
	while (*s != '\0')
	{
		if (*s != '%')
		{
			if (write(1, s, 1) == -1)
				return (-1);
			total++;
		}
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				break ;
			else
			{
				count = print_choice(*s, arguments);
				if (count == -1)
					return (-1);
				total = total + count;
			}
		}
		s++;
	}
	return (total);
}

int	ft_printf(const char *s, ...)
{
	va_list	arguments;
	int		count;
	int		total_count;

	count = 0;
	total_count = 0;
	va_start(arguments, s);
	total_count = helper(s, arguments, count, total_count);
	va_end(arguments);
	return (total_count);
}
/*
#include <stdio.h>

int main(void)
{
	char *str = "abcdef";
	char c = 'c';
	int i = 12345;
	int test = 42;
	int *ptr = &test;
	unsigned int j = 99;
	int hex = 65535;
	int org_result = printf("abcdef\n");
	printf("%d\n", org_result);
	int my_result = ft_printf("abcdef\n");
	printf("%d\n", my_result);
	printf("rest of tests\n");
	org_result = printf("%s\n", str);
	my_result = ft_printf("%s\n", str);
	printf("test 1: org result %d and my result %d\n", org_result, my_result);
	org_result = printf("%d\n", i);
	my_result = ft_printf("%d\n", i);
	printf("test 2: org result %d and my result %d\n", org_result, my_result);
	org_result = printf("%i\n", i);
	my_result = ft_printf("%i\n", i);
	printf("test 3: org result %i and my result %i\n", org_result, my_result);
	org_result = printf("%c\n", c);
	my_result = ft_printf("%c\n", c);
	printf("test 4: org result %d and my result %d\n", org_result, my_result);
	org_result = printf("%p\n", (void*)ptr);
	my_result = ft_printf("%p\n", (void*)ptr);
	printf("test 5: org result %d and my result %d\n", org_result, my_result);
	unsigned int org_uint_result = printf("%u\n", j);
	unsigned int my_uint_result = ft_printf("%u\n", j);
	printf("test 6: org result %u and my result %u\n", org_uint_result, my_uint_result);
	org_result = printf("%x\n", hex);
	my_result = ft_printf("%x\n", hex);
	printf("test 7: org result %d and my result %d\n", org_result, my_result);
	org_result = printf("%X\n", hex);
	my_result = ft_printf("%X\n", hex);
	printf("test 8: org result %d and my result %d\n", org_result, my_result);
	org_result = printf("%%\n");
	my_result = ft_printf("%%\n");
	printf("test 9: org result %d and my result %d\n", org_result, my_result);
	return (0);
}*/
