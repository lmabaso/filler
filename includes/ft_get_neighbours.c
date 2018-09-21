/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_neighbours.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:30:14 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 09:48:38 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list		*ft_get_neighbours(int y, int x, t_obj input)
{
	t_list	*head;
	t_co	tmp;

	head = NULL;
	if (x < input.bx - 1)
	{
		ft_put_to_co(&tmp, x + 1, y);
		ft_lstadd(&head, ft_lstnew(&tmp, sizeof(t_co)));
	}
	if (x > 0)
	{
		ft_put_to_co(&tmp, x - 1, y);
		ft_lstadd(&head, ft_lstnew(&tmp, sizeof(t_co)));
	}
	if (y < input.by - 1)
	{
		ft_put_to_co(&tmp, x, y + 1);
		ft_lstadd(&head, ft_lstnew(&tmp, sizeof(t_co)));
	}
	if (y > 0)
	{
		ft_put_to_co(&tmp, x, y - 1);
		ft_lstadd(&head, ft_lstnew(&tmp, sizeof(t_co)));
	}
	return (head);
}
