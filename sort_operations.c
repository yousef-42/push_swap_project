/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:37:50 by yasmail           #+#    #+#             */
/*   Updated: 2026/05/11 16:55:08 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stack_a)
{
	int	a;
	int	b;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	a = *(int *)(*stack_a)->content;
	b = *(int *)(*stack_a)->next->content;
	if (a > b)
		sa(*stack_a);
}

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = *((int *)(*stack_a)->content);
	b = *((int *)(*stack_a)->next->content);
	c = *((int *)(*stack_a)->next->next->content);
	if (a > b && b < c && a < c)
		sa(*stack_a);
	else if (a > b && b > c)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_4_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		min;

	while (ft_lstsize(*stack_a) > 3)
	{
		tmp = *stack_a;
		min = *((int *)tmp->content);
		while (tmp)
		{
			if (*((int *)tmp->content) < min)
				min = *((int *)tmp->content);
			tmp = tmp->next;
		}
		while (*((int *)(*stack_a)->content) != min)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
