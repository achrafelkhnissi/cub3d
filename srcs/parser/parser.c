/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 06:36:12 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/25 12:59:14 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	1. extention must be .cub
	2. 0 1 N S E W > allowed characters.
	3. Except for the map content, each type of element can be separated by one or more empty line(s).
	4. Except for the map content which always has to be the last, each type of element can be set in any order in the file.
	5. Except for the map, each type of information from an element can be separated by one or more space(s).
	6. Spaces are a valid part of the map and are up to you to handle. 
*/

int	nbr_of_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	print_map(t_map	map)
{
	int	i;

	i = -1;
	printf("---------------------- MAP --------------------------\n");
	while (map.map[++i])
		printf("map[%i]: %s\n", i, map.map[i]);
	printf("map's lines: %i\n", map.row);
	printf("---------------------- TEXTURE ----------------------\n");
	printf("NO: %s\n", map.north_texture);
	printf("SO: %s\n", map.south_texture);
	printf("EA: %s\n", map.east_texture);
	printf("WE: %s\n", map.west_texture);
	printf("---------------------- COLORS -----------------------\n");
	printf("floor: %i, %i, %i\n", map.floor_color.r, map.floor_color.g, map.floor_color.b);
	printf("ceilling: %i, %i, %i\n", map.ceilling_color.r, map.ceilling_color.g, map.ceilling_color.b);
	printf("---------------------- PLAYSR ----------------------\n");
	printf("Player position: x: %i, y: %i\n", map.player.x, map.player.y);
	printf("Starting position: %c\n", map.starting_pos);
	printf("---------------------- FILE -------------------------\n");
	printf("Filename: %s\n", map.filename);
	printf("-----------------------------------------------------\n");
}

void	get_cub_content(t_program *ptr)
{
	int	len;
	int	fd;
	int	i;

	i = 0;
	len = nbr_of_lines(ptr->map.filename);
	ptr->cub_content = malloc(sizeof(char *) * (len + 1));
	if (!ptr->cub_content)
		ft_puterror("Malloc Error: parser.c: 81\n");
	fd = open(ptr->map.filename, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	ptr->cub_content[i] = get_next_line(fd);
	while (i < len && ptr->cub_content[i++])
		ptr->cub_content[i] = get_next_line(fd);
	ptr->cub_content[i] = 0;
	close(fd);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	get_map_textures(t_program *game_ptr)
{
	char	**splited;
	int		i;

	i = 0;
	while (game_ptr->cub_content[i])
	{
		if (game_ptr->cub_content[i][0] == '1'
				|| game_ptr->cub_content[i][0] == ' '
				|| game_ptr->cub_content[i][0] == '0')
			break ;
		splited = ft_split(game_ptr->cub_content[i++], ", \n");
		if (!splited[0])
			return ;
		if (ft_strcmp(splited[0], NORTH_TEXTURE) == EQUAL)
			game_ptr->map.north_texture = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], SOUTH_TEXTURE) == EQUAL)
			game_ptr->map.south_texture = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], EAST_TEXTURE) == EQUAL)
			game_ptr->map.east_texture = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], WEST_TEXTURE) == EQUAL)
			game_ptr->map.west_texture = ft_strdup(splited[1]);
		free_split(splited);
	}
}

void	get_rgb(t_color *color, char **str)
{
	color->r = ft_atoi(str[0]);
	color->g = ft_atoi(str[1]);
	color->b = ft_atoi(str[2]);
}

void	get_colors(t_program *ptr)
{
	char	**splited;
	int		i;

	i = 0;
	while (ptr->cub_content[i])
	{
		if (ptr->cub_content[i][0] == '1'
				|| ptr->cub_content[i][0] == ' '
				|| ptr->cub_content[i][0] == '0')
			break ;
		splited = ft_split(ptr->cub_content[i++], ", \n");
		if (splited[0])
		{
			if (ft_strcmp(splited[0], FLOOR) == EQUAL)
				get_rgb(&ptr->map.floor_color, splited + 1);
			else if (ft_strcmp(splited[0], CEILLING) == EQUAL)
				get_rgb(&ptr->map.ceilling_color, splited + 1);
		}
		free_split(splited);
	}
}

int	get_map_len(t_program *ptr)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ptr->cub_content[i])
	{
		if (ptr->cub_content[i][0] == '1'
				|| ptr->cub_content[i][0] == ' '
				|| ptr->cub_content[i][0] == '0')
		{
			len++;
		}
		i++;
	}
	return (len);
}

int	check_new_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}

void	get_map(t_program *ptr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr->map.row = get_map_len(ptr);
	ptr->map.map = malloc(sizeof(char *) * (ptr->map.row + 1));
	if (!ptr->map.map)
		ft_puterror("Malloc Error: parser.c: 201\n");
	while (ptr->cub_content[i])
	{
		if (ptr->cub_content[i][0] == '1'
				|| ptr->cub_content[i][0] == ' '
				|| ptr->cub_content[i][0] == '0')
		{
			ptr->map.map[j++] = ft_strndup(ptr->cub_content[i],
					ft_strlen(ptr->cub_content[i]) - \
					check_new_line(ptr->cub_content[i]));
		}
		i++;
	}
	ptr->map.map[j] = 0;
}

int	in_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

void	get_player_pos(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->map[row])
	{
		col = 0;
		while (map->map[row][col])
		{
			if (in_charset(map->map[row][col], "NSEW"))
			{
				map->player.x = row;
				map->player.y = col;
				map->starting_pos = map->map[row][col];
				return ;
			}
			col++;
		}
		row++;
	}
}

int	check_extention(char *src, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(src) - ft_strlen(to_find);
	while ((src[j] && to_find[i])
		&& (src[j++] == to_find[i++]))
		;
	if (j == ft_strlen(src))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
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
			if (in_charset(map[row][col], "NSEW"))
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

void	check_map_full(t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (map.map[row])
	{
		col = 0;
		while (map.map[row][col])
		{
			if ((row == 0 && check_north_wall(map.map, row, col))
				|| (row == map.row - 1 && check_south_wall(map.map, row, col)))
				ft_puterror("Invalid map!.\n");
			else if (col == 0 && check_west_wall(map.map, row))
				ft_puterror("Invalid map!.\n");
			else if (col == ft_strlen(map.map[row]) - 1
				&& check_east_wall(map.map, row, col))
				ft_puterror("Invalid map!.\n");
			else if ((row > 0 && row < map.row - 1)
				&& (col > 0 && col < ft_strlen(map.map[row]) - 1))
			{
				if (map.map[row][col] == '0'
					&& (map.map[row + 1][col] == ' ' || map.map[row - 1][col] == ' '
					|| map.map[row][col + 1] == ' ' || map.map[row][col - 1] == ' '))
				{
					printf("space\n");
					ft_puterror("Invalid map!.\n");
				}
			}
			col++;
		}
		row++;
	}
}

void	parse_map(t_program *ptr)
{
	if (check_extention(ptr->map.filename, ".cub")
		== EXIT_FAILURE)
		ft_puterror("Wrong extention.\n");
	get_cub_content(ptr);
	get_map(ptr);
	check_map(ptr->map.map);
	check_map_full(ptr->map);
	get_map_textures(ptr);
	get_colors(ptr);
	get_colors(ptr);
	get_player_pos(&ptr->map);
}