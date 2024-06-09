/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:27:28 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/06/09 17:39:23 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_choice(char specifier, va_list arguments)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(arguments, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(arguments, char *));
	else if (specifier == 'd' || specifier == 'u' || specifier == 'i')
		count += ft_putnbr(va_arg(arguments, int), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		count += ft_putnbr(va_arg(arguments, unsigned int), 16, specifier);
	else if (specifier == '%')
		count += ft_putchar(specifier);
	else if (specifier == 'p')
		count += ft_pointer(va_arg(arguments, void *));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arguments;
	int		count;

	va_start(arguments, s);
	count = 0;
	while (*s != '\0')
	{
		if (*s != '%')
		{
			write(1, s, 1);
			count++;
		}
		if (*s == '%')
		{
			count += print_choice(*(++s), arguments);
		}
		++s;
	}
	va_end(arguments);
	return (count);
}
/*
int main(void)
{
	char *str = "abcde fgh12344 jdhx";
	int my_print = ft_printf("%s", str);
	int my_print2 = ft_printf("\n");
	int org_print = printf("%s", str);
	int org_print2 = printf("\n");
	printf("%d\n %d\n %d\n %d\n", my_print, my_print2, org_print, org_print2);
	return (0);
}
int print_result = ft_printf("something\n");
printf("%d\n", result);
return (0);

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
