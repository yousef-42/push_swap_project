/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:58:22 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:46:10 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur(int n, int fd)
{
	ssize_t	ret;
	char	numchar;
	int		num;

	num = n;
	numchar = 'a';
	if (num <= 0)
		return ;
	numchar = (num % 10) + '0';
	num = num / 10;
	recur(num, fd);
	ret = write(fd, &numchar, 1);
	(void)ret;
}

void	ft_putnbr_fd(int n, int fd)
{
	ssize_t	ret;
	int		num;

	num = n;
	if (num == 0)
	{
		ret = write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		ret = write(fd, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		ret = write(fd, "-", 1);
		num *= -1;
	}
	recur(num, fd);
	(void)ret;
}
