/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 08:31:00 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/25 17:10:25 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_get_board(t_obj *input)
{
	int i;

	if (ft_isdigit(*input->line))
	{
		i = 0;
		if (!input->board)
			if (!(input->board = (char **)malloc(sizeof(char *)
							* input->by + 1)))
				return (-1);
		while (ft_isdigit(input->line[i]) || ft_isspace(input->line[i]))
			i++;
		input->board[input->by] = NULL;
		input->board[input->i] = ft_strdup(&input->line[i]);
		input->i += 1;
		return (1);
	}
	return (0);
}

void	ft_get_piece(t_obj *input)
{
	char **tmp;

	if (ft_strncmp(input->line, "Piece ", 6) == 0)
	{
		tmp = ft_strsplit(input->line, ' ');
		input->py = ft_atoi(tmp[1]);
		input->px = ft_atoi(tmp[2]);
		ft_free_2dchr(tmp);
		free(input->line);
		input->realpiece = ft_get_physical_sqr(input);
		input->isdone = 1;
	}
}

void	ft_get_info(t_obj *input)
{
	char **tmp;

	if (ft_strncmp(input->line, "$$$ exec ", 9) == 0)
	{
		input->player = ft_strsub(input->line, 9, 2);
		input->mypiece = (ft_strcmp(input->player, "p1") == 0) ? 'O' : 'X';
		input->oppiece = (input->mypiece == 'O') ? 'X' : 'O';
		free(input->line);
	}
	if (ft_strncmp(input->line, "Plateau ", 8) == 0)
	{
		tmp = ft_strsplit(input->line, ' ');
		input->by = ft_atoi(tmp[1]);
		input->bx = ft_atoi(tmp[2]);
		ft_free_2dchr(tmp);
		free(input->line);
	}
	ft_get_board(input);
	ft_get_piece(input);
}
