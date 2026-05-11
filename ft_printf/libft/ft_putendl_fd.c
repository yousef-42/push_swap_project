/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:49:35 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:45:18 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ssize_t	ret;

	if (!s)
		return ;
	ret = write(fd, s, ft_strlen(s));
	ret = write(fd, "\n", 1);
	(void)ret;
}
