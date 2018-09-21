/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:09:20 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 10:20:43 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_board_x(int i, t_obj *input)
{
	int		j;

	j = 0;
	while (j < input->bx)
	{
		input->aboard[i][j].neighbours = ft_get_neighbours(i, j, *input);
		input->aboard[i][j].x = i;
		input->aboard[i][j].y = j;
		input->aboard[i][j].state = input->board[i][j];
		if (input->aboard[i][j].state == '.')
			input->aboard[i][j].score = 0;
		if (ft_toupper(input->aboard[i][j].state) == input->mypiece)
			input->aboard[i][j].score = -2;
		if (ft_toupper(input->aboard[i][j].state) == input->oppiece)
			input->aboard[i][j].score = -1;
		j++;
	}
}

void	ft_get_score(t_obj *input)
{
	int		i;
	int		j;
	t_co	tmp1;
	t_co	tmp;

	i = 0;
	while (i < input->by)
	{
		j = 0;
		while (j < input->bx)
		{
			if (input->aboard[i][j].score == 0)
			{
				ft_put_to_co(&tmp1, j, i);
				tmp = ft_find_close(i, j, *input);
				input->aboard[i][j].score = (int)ft_get_distance(tmp, tmp1);
			}
			j++;
		}
		i++;
	}
}

void	ft_makeboard(t_obj *input)
{
	int		i;

	i = 0;
	if (!(input->aboard = (t_spot **)malloc(sizeof(t_spot *) * input->by)))
		return ;
	while (i < input->by)
	{
		if (!(input->aboard[i] = (t_spot *)malloc(sizeof(t_spot) * input->bx)))
			return ;
		ft_board_x(i, input);
		i++;
	}
	ft_get_score(input);
}
