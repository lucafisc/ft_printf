/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:08:34 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 12:32:22 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int ft_putstr_len(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ft_putstr_len("(null)");
	while (s[i])
		i += ft_putchar_len(s[i]);
	return (i);
}
