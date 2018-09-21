/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:22:25 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 10:23:02 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_co		ft_relative_b(t_co board, t_co *piece)
{
	t_co	correct;

	correct.y = board.y - piece->y;
	correct.x = board.x - piece->x;
	return (correct);
}

void		ft_play(t_co toplace)
{
	ft_putnbr(toplace.y);
	ft_putchar(' ');
	ft_putnbr(toplace.x);
	ft_putchar('\n');
}
