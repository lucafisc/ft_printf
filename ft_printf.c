/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:37:05 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 12:31:37 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	sort_input(va_list args, char c)
{
	int size;

	if (c == 'c')
		size = ft_putchar_len(va_arg(args, int));
	else if (c == 's')
		size = ft_putstr_len(va_arg(args, char *));
	else if (c == 'i')
		size = ft_putstr_len(ft_itoa(va_arg(args, int)));
	else if (c == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		size = ft_putchar_len(c);
	else if (c == 'p')
	{
		size = ft_putstr_len("0x");
		ft_putnbr_hex(va_arg(args, unsigned long long), 0);
	}
	return (size);
}

int	ft_print(const char *str, ...)
{
	va_list	args;
	int	size;

	size = 0;
	va_start(args, str);
	while (*str)
	{
		if (ft_is_placeholder(*str, *(str + 1)))
		{
			size += sort_input(args, *(str + 1));
			str++;
		}
		else
			size += ft_putchar_len(*str);
		str++;
	}
	va_end(args);
	return (size);
}

int	main(void)
{
	char *my_str = NULL;
	ft_print("%s, %i", my_str, 23747843);
	// ft_print("h%ii%si%c %i, %%i \n", -2147483648, my_str, 'y', 88);
	// printf("h%lii%si%c %i, %%i \n", -2147483648, my_str, 'y', 88);
}