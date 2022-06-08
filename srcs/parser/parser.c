/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 06:36:12 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/08 11:07:44 by ael-khni         ###   ########.fr       */
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

void	print_map(char **content)
{
	int	i;

	i = -1;
	while (content[++i])
		printf("content[%i]: %s\n", i, content[i]);
	putchar('\n');
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
	{
		printf("malloc error:parser.c:42\n");
		exit(EXIT_FAILURE);
	}
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
				|| game_ptr->cub_content[i][0] == ' ')
			break ; // parse map here if found.
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

// void	parse_map(t_program *ptr)
// {
	
// }