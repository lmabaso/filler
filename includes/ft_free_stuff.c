/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:24:50 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 11:41:55 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_deletelist(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*head = NULL;
}

void		ft_free_boards(t_obj *input)
{
	input->i = 0;
	while (input->i < input->by)
	{
		input->j = 0;
		while (input->j < input->bx)
		{
			ft_deletelist(&input->aboard[input->i][input->j].neighbours);
			input->j++;
		}
		free(input->aboard[input->i]);
		input->i++;
	}
	free(input->aboard);
}

void		ft_freeall(t_obj *input)
{
	int		i;

	i = 0;
	while (i < input->by)
	{
		free(input->board[i]);
		i++;
	}
	free(input->board);
}

void		ft_free_2dchr(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void		ft_makezero(t_obj *input)
{
	input->isdone = 0;
	ft_put_to_co(&input->bestmove, 0, 0);
	ft_deletelist(&input->realpiece);
	ft_deletelist(&input->moves);
	input->i = 0;
	input->j = 0;
}
