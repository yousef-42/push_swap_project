/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:36:45 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/11 20:38:51 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*structvar;

	structvar = malloc(sizeof(t_list));
	if (!structvar)
		return (NULL);
	structvar->content = content;
	structvar->next = NULL;
	return (structvar);
}
