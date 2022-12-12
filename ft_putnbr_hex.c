/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:32:35 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/12 10:46:33 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(unsigned int n, char caps)
{
	// printf("number here!: %d\n", n);
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, caps);
		ft_putnbr_hex(n % 16, caps);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (caps)
				ft_putchar_fd((n - 10 + 'A'), 1);
			else
				ft_putchar_fd((n - 10 + 'a'), 1);
		}
	}
}