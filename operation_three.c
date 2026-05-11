/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:23:29 by yasmail           #+#    #+#             */
/*   Updated: 2026/02/21 21:51:39 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	void	*tmp;

	if (ft_lstsize(stack_a) < 2)
		return ;
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
	void	*tmp;

	if (ft_lstsize(stack_b) < 2)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
