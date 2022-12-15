/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:37:05 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/15 07:30:58 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	sort_input(va_list args, char c)
{
	int		size;
	char	*pt;

	pt = NULL;
	if (c == 'c')
		size = ft_putchar_len(va_arg(args, int));
	else if (c == 's')
		size = ft_putstr_len(va_arg(args, char *));
	else if (c == '%')
		size = ft_putchar_len(c);
	else if (c == 'p')
		pt = ft_ptrtoa(va_arg(args, unsigned long));
	else if (c == 'i' || c == 'd')
		pt = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		pt = ft_iutoa(va_arg(args, unsigned int));
	else if (c == 'x')
		pt = ft_hextoa(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		pt = ft_hextoa(va_arg(args, unsigned int), 1);
	if (pt)
	{
		size = ft_putstr_len(pt);
	//	free(pt);
		pt = NULL;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

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

// int	main(void)
// {
// 	ft_printf("my printf:\n %p %p \n", 0, 0);
// 	printf("real printf:\n %p %p \n", 0, 0);
// 	// char my_str[] = "Hello world!";
// 	// char *pt;
// 	// pt = my_str;
// }