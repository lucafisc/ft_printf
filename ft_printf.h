/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:19 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 20:56:00 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_len(char c);
int		ft_putstr_len(char *s);
int		ft_is_placeholder(char a, char b);
char	*ft_iutoa(unsigned int n);
char	*ft_itoa(int n);
char	*ft_str_rev(char *str);
char	*ft_hextoa(unsigned long n, char caps);
size_t	ft_strlen(const char *s);
int		ft_putptr(unsigned long pt);

#endif