/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:43:02 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/15 07:29:35 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrtoa(unsigned long pt)
{
	int		size;
	char	*str;

	if (!pt)
		str = ft_strdup("(nil)");
	else
		str = ft_strjoin("0x", ft_hextoa(pt, 0));
	return (str);
}
