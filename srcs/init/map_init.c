/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:25:04 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/27 21:35:59 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->row = -1;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->filename = NULL;
	map->starting_pos = '\0';
	init_color(&map->floor_color);
	init_color(&map->ceilling_color);
	map->player.x = 0;
	map->player.y = 0;
}

void	init_game(t_program *game)
{
	init_map(&game->map);
	game->mlx = mlx_init();
	game->cub_content = NULL;
	game->screen_h = 1024;
	game->screen_w = 1024;
	game->x = 0;
	ft_new_window(game);
	game->img.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	game->img.arr = (int *)mlx_get_data_addr(game->img.ptr, &(game->img.bpp), \
		&(game->img.len), &(game->img.endian));
}

void	ext_start_game(t_program *game)
{
	if (game->map.starting_pos == 'E')
	{
		game->dir_x = 0.0;
		game->dir_y = 1.0;
		game->plane_x = 0.66;
		game->plane_y = 0.0;
	}
	if (game->map.starting_pos == 'W')
	{
		game->dir_x = 0.0;
		game->dir_y = -1.0;
		game->plane_x = -0.66;
		game->plane_y = 0.0;
	}
}

void	start_game(t_program *game)
{
	game->r_angle = 0.2;
	game->m_speed = 0.4;
	game->plane_x = 0.0;
	game->plane_y = 0.66;
	game->pos_x = game->map.player.x;
	game->pos_y = game->map.player.y;
	if (game->map.starting_pos == 'N')
	{
		game->dir_x = -1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = 0.66;
	}
	if (game->map.starting_pos == 'S')
	{
		game->dir_x = 1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = -0.66;
	}
	ext_start_game(game);
}
