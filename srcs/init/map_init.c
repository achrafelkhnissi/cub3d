/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:25:04 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/09 09:22:01 by ael-khni         ###   ########.fr       */
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
	game->mlx = NULL;
	game->win_ptr = NULL;
	game->img_ptr = NULL;
	game->cub_content = NULL;
	game->screen_h = 0;
	game->screen_w = 0;
	game->step_x = 0;
	game->step_y = 0;
	game->hit = 0;
	game->side = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->line_height = 0;
	game->draw_end = 0;
	game->draw_end = 0;
	game->pos_x = 0;
	game->pos_y = 0;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0;
	game->camera_x = 0;
	game->raydir_x = 0;
	game->raydir_x = 0;
	game->delta_dist_x = 0;
	game->delta_dist_y = 0;
	game->side_dist_x = 0;
	game->side_dist_x = 0;
	game->perp_wall_dist = 0;
}