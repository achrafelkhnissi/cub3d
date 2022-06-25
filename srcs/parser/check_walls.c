/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:05:03 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/25 12:45:00 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// !Maybe you should check if the player next to the wall 
// because now we only check if there's '1' or ' ' next to it.

// NOTE: we can remove row and change it to 0
int	check_north_wall(char **map, int row, int col)
{
	if ((map[row][col] != '1' && map[row][col] != ' ')
		|| (map[row][col] == ' ' && (map[row + 1][col] != ' '
		&& map[row + 1][col] != '1')))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_south_wall(char **map, int row, int col)
{
	if (map[row][col] != '1' && map[row][col] != ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_west_wall(char **map, int row)
{
	if (map[row][0] != '1' && map[row][0] != ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_east_wall(char **map, int row, int col)
{
	if (map[row][col] != '1' && map[row][col] != ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
