/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:23:40 by yasmail           #+#    #+#             */
/*   Updated: 2026/05/04 15:11:20 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int *)stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	failed_sort(int argc, char **args)
{
	ft_printf("Error\n");
	if (argc == 2)
		free_split(args);
}

static int	error_check(int argc, char **args, t_list **stack_a)
{
	int	i;
	int	num;

	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
		{
			failed_sort(argc, args);
			ft_lstclear(stack_a, free);
			return (1);
		}
		num = ft_atoi(args[i]);
		if (check_duplicate(*stack_a, num))
		{
			failed_sort(argc, args);
			ft_lstclear(stack_a, free);
			return (1);
		}
		ft_lstadd_back(stack_a, ft_lstnew(ft_calloc(1, sizeof(int))));
		*(int *)ft_lstlast(*stack_a)->content = num;
		i++;
	}
	return (0);
}

static void	sort_arguments(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size <= 5)
		sort_4_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (error_check(argc, args, &stack_a))
		return (1);
	if (argc == 2)
		free_split(args);
	if (ft_lstsize(stack_a) == 1 || is_sorted(stack_a))
		return (ft_lstclear(&stack_a, free), 0);
	sort_arguments(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
