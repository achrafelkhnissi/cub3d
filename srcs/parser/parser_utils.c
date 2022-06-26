/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 10:41:56 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/26 16:33:32 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map	map)
{
	int	i;

	i = -1;
	printf("---------------------- MAP --------------------------\n");
	while (map.map[++i])
		printf("map[%i]: %s\n", i, map.map[i]);
	printf("Map's Lines: %i, Col: %i\n", map.row, map.col);
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

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	check_new_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
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
