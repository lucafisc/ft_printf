/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:43:02 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 20:55:37 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long pt)
{
	int		size;
	char	*str;

	if (!pt)
		size = ft_putstr_len("(nil)");
	else
	{
		size = ft_putstr_len("0x");
		str = ft_hextoa(pt, 0);
		size += ft_putstr_len(str);
		free(str);
	}
	return (size);
}
