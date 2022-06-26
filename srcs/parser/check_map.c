/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:38:04 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/26 11:20:58 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_player_surroundings(char **map, int row, int col)
{
	if (map[row][col + 1] == ' ' || map[row][col - 1] == ' '
		|| map[row + 1][col] == ' ' || map[row - 1][col] == ' ')
		ft_puterror("Invalid map\n");
	return (EXIT_SUCCESS);
}

void	check_map(char **map)
{
	int	row;
	int	col;
	int	found;

	row = 0;
	found = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!in_charset(map[row][col], " 01NSEW"))
				ft_puterror("Invalid character found in map.\n");
			if (in_charset(map[row][col], "NSEW")
				&& !check_player_surroundings(map, row, col))
				found++;
			col++;
		}
		row++;
	}
	if (!found)
		ft_puterror("Player not found!.\n");
	else if (found > 1)
		ft_puterror("This is not a multiplayer game..\n");
}

void	map_checks_(t_map map, int row, int col)
{
	if ((row == 0 && check_wall(map.map, row, col))
		|| (row == map.row - 1 && check_wall(map.map, row, col)))
		ft_puterror("Invalid map!.\n");
	else if (col == 0 && check_wall(map.map, row, col))
		ft_puterror("Invalid map!.\n");
	else if (col == ft_strlen(map.map[row]) - 1
		&& check_wall(map.map, row, col))
		ft_puterror("Invalid map!.\n");
	else if ((row > 0 && row < map.row - 1)
		&& (col > 0 && col < ft_strlen(map.map[row]) - 1))
	{
		if (map.map[row][col] == '0'
			&& (map.map[row + 1][col] == ' ' || map.map[row - 1][col] == ' '
			|| map.map[row][col + 1] == ' ' || map.map[row][col - 1] == ' '))
			ft_puterror("Invalid map!.\n");
	}
}

void	check_map_full(t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (map.map[row])
	{
		col = 0;
		if (check_extended_wall(map.map, row))
			ft_puterror("Invalid map!. (new)\n");
		while (map.map[row][col])
		{
			map_checks_(map, row, col);
			col++;
		}
		row++;
	}
}
