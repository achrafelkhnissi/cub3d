/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:05:03 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/26 11:24:19 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_wall(char **map, int row, int col)
{
	if (map[row][col] != '1' && map[row][col] != ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_wall_(char **map, int row, int i)
{
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_extended_wall(char **map, int row)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(map[row]);
	l2 = 0;
	if (map[row + 1])
		l2 = ft_strlen(map[row + 1]);
	if (l1 > l2 && l2 > 0)
	{
		if (check_wall_(map, row, l2))
			return (EXIT_FAILURE);
	}
	else if (l2 > l1)
	{
		if (check_wall_(map, row + 1, l1))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
