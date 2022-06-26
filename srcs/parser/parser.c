/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:20:21 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/26 16:44:47 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	parse_map(t_program *ptr)
{
	if (check_extention(ptr->map.filename, ".cub")
		== EXIT_FAILURE)
		ft_puterror("Wrong extention.\n");
	get_cub_content(ptr);
	check_cub_content(ptr->cub_content);
	get_map_textures(ptr);
	get_colors(ptr);
	get_map(ptr);
	get_player_pos(&ptr->map);
	check_map(ptr->map.map);
	check_map_full(ptr->map);
	print_map(ptr->map);
}
