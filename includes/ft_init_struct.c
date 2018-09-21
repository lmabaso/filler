/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:46:25 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 10:46:48 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_struct(t_obj *input)
{
	input->bx = 0;
	input->by = 0;
	input->px = 0;
	input->py = 0;
	input->i = 0;
	input->j = 0;
	input->isdone = 0;
	input->player = NULL;
	input->line = NULL;
	input->mypiece = '\0';
	input->oppiece = '\0';
	input->board = NULL;
	input->aboard = NULL;
	input->realpiece = NULL;
	input->moves = NULL;
	ft_put_to_co(&input->bestmove, 0, 0);
}
