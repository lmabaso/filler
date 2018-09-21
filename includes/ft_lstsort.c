/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:49:47 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 10:00:52 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_fb_split(t_list *source, t_list **front, t_list **back)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

t_list		*ft_sorted_merge(t_list *a, t_list *b)
{
	t_list	*result;
	t_best	*ta;
	t_best	*tb;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	ta = a->content;
	tb = b->content;
	if (ta->score <= tb->score)
	{
		result = a;
		result->next = ft_sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = ft_sorted_merge(a, b->next);
	}
	return (result);
}

void		ft_mergesort(t_list **head)
{
	t_list	*current;
	t_list	*a;
	t_list	*b;

	current = *head;
	if ((current == NULL) || (current->next == NULL))
		return ;
	ft_fb_split(current, &a, &b);
	ft_mergesort(&a);
	ft_mergesort(&b);
	*head = ft_sorted_merge(a, b);
}
