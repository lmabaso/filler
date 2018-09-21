/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:16:58 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 11:18:48 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

void	ft_scoremoves(t_list *moves, t_list **lst_opt, t_obj *input)
{
	t_best	*tmp;
	t_co	eval;
	t_best	optimal;

	while (moves)
	{
		tmp = moves->content;
		ft_best_to_co(&eval, *tmp);
		if (ft_toplace(eval, *input, &optimal))
			ft_lstadd(lst_opt, ft_lstnew(&optimal, sizeof(t_best)));
		moves = moves->next;
	}
}

int		ft_best_move(t_list *moves, t_obj *input)
{
	t_best	*tmp;
	t_list	*lst_opt;

	input->i = 0;
	lst_opt = NULL;
	if (moves == NULL)
		return (0);
	ft_mergesort(&moves);
	tmp = moves->content;
	ft_best_to_co(&input->bestmove, *tmp);
	ft_scoremoves(moves, &lst_opt, input);
	if (lst_opt == NULL)
		return (0);
	ft_mergesort(&lst_opt);
	tmp = lst_opt->content;
	ft_best_to_co(&input->bestmove, *tmp);
	ft_deletelist(&moves);
	ft_deletelist(&lst_opt);
	return (1);
}

int		main(void)
{
	t_obj	*input;

	if (!(input = ft_memalloc(sizeof(t_obj))))
		return (-1);
	ft_init_struct(input);
	while (1)
	{
		if (!get_next_line(0, &input->line))
			return (1);
		ft_get_info(input);
		if (input->isdone)
		{
			ft_makeboard(input);
			if (ft_get_all_moves(input))
				if (ft_best_move(ft_lowcost(input), input))
					ft_play(input->bestmove);
				else
					ft_play(input->bestmove);
			else
				ft_play(input->bestmove);
			ft_makezero(input);
		}
	}
	free(input);
	return (1);
}
