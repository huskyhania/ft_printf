/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:32:16 by hskrzypi          #+#    #+#             */
/*   Updated: 2024/06/10 22:10:15 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdint.h>

int			ft_putchar(int c);
int			ft_putstr(char *s);
int			ft_putnbr_recursive(long n, int base, char is_upper, int result);
int			ft_putnbr(long n, int base, char is_upper);
int			ft_pointer(void *ptr, int i, int length, char *base_chars);
int			ft_printf(const char *s, ...);

#endif
