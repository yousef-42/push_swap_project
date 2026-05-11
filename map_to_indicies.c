/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_indicies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:39:54 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/11 19:50:49 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_list *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	i = 0;
	while (stack)
	{
		arr[i++] = *(int *)stack->content;
		stack = stack->next;
	}
	return (arr);
}

static int	*sort_array(t_list *stack)
{
	int	*arr;
	int	tmp;
	int	i;
	int	j;

	j = 0;
	i = 0;
	arr = stack_to_array(stack, ft_lstsize(stack));
	while (i < ft_lstsize(stack) - 1)
	{
		j = i;
		while (j < ft_lstsize(stack))
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

static int	get_rank(int *arr, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (0);
}

void	map_to_indices(t_list *stack)
{
	int		*arr;
	t_list	*tmp_stack;
	int		size;
	int		val;
	int		rank;

	arr = sort_array(stack);
	tmp_stack = stack;
	size = ft_lstsize(stack);
	while (tmp_stack)
	{
		val = *(int *)tmp_stack->content;
		rank = 0;
		rank = get_rank(arr, val, size);
		*(int *)tmp_stack->content = rank;
		tmp_stack = tmp_stack->next;
	}
	free(arr);
}
