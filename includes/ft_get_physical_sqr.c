/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_physical_sqr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:14:11 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/19 14:18:54 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list		*ft_get_physical_sqr(t_obj *input)
{
	t_co	*tmp;
	t_list	*head;

	head = NULL;
	input->i = 0;
	tmp = NULL;
	if (!(tmp = (t_co *)malloc(sizeof(t_co))))
		return (NULL);
	while (input->i < input->py)
	{
		input->j = 0;
		get_next_line(0, &input->line);
		while (input->j < input->px)
		{
			if (input->line[input->j] == '*')
			{
				ft_put_to_co(tmp, input->j, input->i);
				ft_lstadd(&head, ft_lstnew(tmp, sizeof(t_co)));
			}
			input->j++;
		}
		input->i++;
		free(input->line);
	}
	return (head);
}
