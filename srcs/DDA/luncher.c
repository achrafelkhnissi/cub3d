/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luncher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:17:39 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/27 21:27:04 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ext_init_draw(t_program *game_ptr)
{
	if (game_ptr->raydir_x < 0)
	{
		game_ptr->step_x = -1;
		game_ptr->side_dist_x = (game_ptr->pos_x - game_ptr->map_x) \
			* game_ptr->delta_dist_x;
	}
	else
	{
		game_ptr->step_x = 1;
		game_ptr->side_dist_x = (game_ptr->map_x + 1.0 - game_ptr->pos_x) \
			* game_ptr->delta_dist_x;
	}
	if (game_ptr->raydir_y < 0)
	{
		game_ptr->step_y = -1;
		game_ptr->side_dist_y = (game_ptr->pos_y - game_ptr->map_y) \
			* game_ptr->delta_dist_y;
	}
	else
	{
		game_ptr->step_y = 1;
		game_ptr->side_dist_y = (game_ptr->map_y + 1.0 - game_ptr->pos_y) \
			* game_ptr->delta_dist_y;
	}
}

void	init_draw_var(t_program *game_ptr)
{
	game_ptr->camera_x = 2 * (game_ptr->x / (double)(game_ptr->screen_w)) - 1;
	game_ptr->raydir_x = game_ptr->dir_x + game_ptr->plane_x \
		* game_ptr->camera_x;
	game_ptr->raydir_y = game_ptr->dir_y + game_ptr->plane_y \
		* game_ptr->camera_x;
	game_ptr->map_x = (int)game_ptr->pos_x;
	game_ptr->map_y = (int)game_ptr->pos_y;
	game_ptr->delta_dist_x = sqrt(1 + pow(game_ptr->raydir_y, 2) \
		/ pow(game_ptr->raydir_x, 2));
	game_ptr->delta_dist_y = sqrt(1 + pow(game_ptr->raydir_x, 2) \
		/ pow(game_ptr->raydir_y, 2));
	game_ptr->hit = 0;
	ext_init_draw(game_ptr);
}

void	raycast(t_program *game_ptr)
{
	while (game_ptr->hit == 0)
	{
		if (game_ptr->side_dist_x < game_ptr->side_dist_y)
		{
			game_ptr->side_dist_x += game_ptr->delta_dist_x;
			game_ptr->map_x += game_ptr->step_x;
			game_ptr->side = 0;
		}
		else
		{
			game_ptr->side_dist_y += game_ptr->delta_dist_y;
			game_ptr->map_y += game_ptr->step_y;
			game_ptr->side = 1;
		}
		if (game_ptr->map.map[game_ptr->map_x][game_ptr->map_y] == '1')
			game_ptr->hit = 1;
	}
	if (game_ptr->side == 0)
		game_ptr->perp_wall_dist = fabs((game_ptr->map_x - game_ptr->pos_x + \
		(1 - game_ptr->step_x) / 2) / game_ptr->raydir_x);
	else
		game_ptr->perp_wall_dist = fabs((game_ptr->map_y - game_ptr->pos_y + \
		(1 - game_ptr->step_y) / 2) / game_ptr->raydir_y);
}

void	calc_distance(t_program *game_ptr)
{
	if (!game_ptr->perp_wall_dist)
		game_ptr->perp_wall_dist = 1;
	game_ptr->line_height = (int)(game_ptr->screen_h \
		/ game_ptr->perp_wall_dist);
	game_ptr->draw_start = -game_ptr->line_height / 2 + game_ptr->screen_h / 2;
	if (game_ptr->draw_start < 0)
		game_ptr->draw_start = 0;
	game_ptr->draw_end = game_ptr->line_height / 2 + game_ptr->screen_h / 2;
	if (game_ptr->draw_end >= game_ptr->screen_h)
		game_ptr->draw_end = game_ptr->screen_h - 1;
}

int	lunch_game(void *ptr)
{
	t_program	*game_ptr;

	game_ptr = ptr;
	mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
	draw(game_ptr);
	return (0);
}
