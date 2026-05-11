/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:30:15 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:37:39 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

static int	handle_overflow(long result, int digit, int sign)
{
	if (sign == 1 && result > (LONG_MAX - digit) / 10)
		return (1);
	if (sign == -1 && - result < (LONG_MIN + digit) / 10)
		return (-1);
	return (0);
}

static long	ov_condition(int ov)
{
	if (ov == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		digit;
	int		ov;

	result = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		ov = handle_overflow(result, digit, sign);
		if (ov != 0)
			return (ov_condition(ov));
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}
