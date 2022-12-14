/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:37:05 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/13 17:55:25 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>

int	is_ph_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
	|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}
int	is_ph(char a, char b)
{
	if (a == '%' && is_ph_char(b))
		return (1);
	return (0);
}

int	count_args(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (is_ph(*str, *(str + 1)))
			count++;
		str++;
	}
	return (count);
}

void sort_input(va_list args, char c)
{
	if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (c == 'u')
		ft_putnbruns_fd(va_arg(args, int), 1);
	else if (c == 'p')
		{
			ft_putstr_fd("0x", 1);
			ft_putnbr_hex(va_arg(args, unsigned long long), 0);
		}
	else if (c == '%')
		ft_putchar_fd(c, 1);
}

int	is_percent_char(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

int is_percent(char a, char b)
{
	if(is_percent_char(a) && is_percent_char(b))
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	// int	num_args;

	// num_args = count_args(str);
	va_start(args, str);
	while (*str)
	{
		if (is_ph(*str, *(str + 1)) || is_percent(*str, *(str + 1)))
		{
			sort_input(args, *(str + 1));
			str += 2;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char my_str[] = "This is a String!!!!!!!!!";
	char *pt;

	pt = my_str;
	ft_printf("h%ii%si%c %i, %%i %x %p %u %d\n", -2147483648, my_str, 'y', 88, 1234948, pt, 2147483650, 4444);
	printf("h%lii%si%c %i, %%i %x %p %lu %d\n", -2147483648, my_str, 'y', 88, 1234948, pt, 2147483650, 4444);
}