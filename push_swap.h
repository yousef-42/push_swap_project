/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:24:00 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:53:36 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "stdio.h"
# include <stdlib.h>

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack_a);
void	sort_4_5(t_list **stack_a, t_list **stack_b);
void	map_to_indices(t_list *stack);
int		is_valid_int(char *str);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	free_split(char **split);
long	ft_atol(const char *str);
int		is_sorted(t_list *stack);

#endif