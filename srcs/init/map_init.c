/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:25:04 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/27 12:42:57 by ael-khni         ###   ########.fr       */
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

void	init_game_ext(t_program *game)
{
	game->line_height = -1;
	game->draw_end = -1;
	game->draw_end = -1;
	game->pos_x = -1;
	game->pos_y = -1;
	game->dir_x = -1;
	game->dir_y = -1;
	game->plane_x = -1;
	game->plane_y = -1;
	game->camera_x = -1;
	game->raydir_x = -1;
	game->raydir_x = -1;
	game->delta_dist_x = -1;
	game->delta_dist_y = -1;
	game->side_dist_x = -1;
	game->side_dist_x = -1;
	game->perp_wall_dist = -1;
}

void	init_game(t_program *game)
{
	init_map(&game->map);
	game->mlx = NULL;
	game->win_ptr = NULL;
	game->img_ptr = NULL;
	game->cub_content = NULL;
	game->screen_h = -1;
	game->screen_w = -1;
	game->step_x = -1;
	game->step_y = -1;
	game->hit = -1;
	game->side = -1;
	game->map_x = -1;
	game->map_y = -1;
	init_game_ext(game);
}
