/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:18:08 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 18:46:07 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*prev;
	t_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	t_list	*prev;
	t_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_printf("pb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_printf("pa\n");
}
