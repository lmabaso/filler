/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:21:00 by lmabaso           #+#    #+#             */
/*   Updated: 2018/07/20 10:22:11 by lmabaso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

double		ft_sqrt(double num)
{
	int		i;
	int		result;

	i = 1;
	result = 1;
	if (num == 0 || num == 1)
		return (num);
	while (result <= num)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

double		ft_get_distance(t_co a, t_co b)
{
	double	distance;

	distance = ft_sqrt((a.x - b.x) * (a.x - b.x) +
			(a.y - b.y) * (a.y - b.y));
	return (distance);
}
