/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 17:52:20 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:53:13 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*current;
	int		curr_val;
	int		next_val;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		curr_val = *(int *)current->content;
		next_val = *(int *)current->next->content;
		if (curr_val > next_val)
			return (0);
		current = current->next;
	}
	return (1);
}
