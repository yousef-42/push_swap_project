/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 19:14:38 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/11 19:29:20 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	binary_radix_sort(t_list **stack_a, t_list **stack_b, int max_bits,
		int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (!*stack_a)
				break ;
			num = *(int *)(*stack_a)->content;
			if (((num >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;

	max_bits = 0;
	if (!stack_a || !*stack_a)
		return ;
	size = ft_lstsize(*stack_a);
	if (size <= 1)
		return ;
	map_to_indices(*stack_a);
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	binary_radix_sort(stack_a, stack_b, max_bits, size);
}
