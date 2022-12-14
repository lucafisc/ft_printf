/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:40:19 by lde-ross          #+#    #+#             */
/*   Updated: 2022/12/14 12:30:03 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTFT
#define LIBFTPRINTFT
# include <stdarg.h>
# include <unistd.h>

void ft_putnbr_hex(unsigned long long n, char format);
int	ft_print(const char *str, ...);
void	ft_putnbruns_fd(unsigned int n, int fd);
int ft_putchar_len(char c);
int ft_putstr_len(char *s);
int	ft_is_placeholder(char a, char b);

#endif