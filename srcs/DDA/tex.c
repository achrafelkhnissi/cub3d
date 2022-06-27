/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:24:02 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/27 22:03:58 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_tex(t_program *game_ptr)
{
	if (game_ptr->side == 0 && game_ptr->step_x == -1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, game_ptr->\
		map.north_texture, &game_ptr->tex.width, &game_ptr->tex.height);
	if (game_ptr->side == 0 && game_ptr->step_x == 1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, game_ptr->\
		map.south_texture, &game_ptr->tex.width, &game_ptr->tex.height);
	if (game_ptr->side == 1 && game_ptr->step_y == -1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, game_ptr->\
		map.west_texture, &game_ptr->tex.width, &game_ptr->tex.height);
	if (game_ptr->side == 1 && game_ptr->step_y == 1)
		game_ptr->tex.ptr = mlx_xpm_file_to_image(game_ptr->mlx, game_ptr->\
		map.east_texture, &game_ptr->tex.width, &game_ptr->tex.height);
	game_ptr->tex.arr = (int *)mlx_get_data_addr(game_ptr->tex.ptr, &game_ptr->\
		tex.len, &game_ptr->tex.bpp, &game_ptr->tex.endian);
}

void	init_tex(t_program *game_ptr)
{
	if (game_ptr->side == 0)
		game_ptr->wallx = game_ptr->pos_y + game_ptr->perp_wall_dist * \
		game_ptr->raydir_y;
	else
		game_ptr->wallx = game_ptr->pos_x + game_ptr->perp_wall_dist * \
		game_ptr->raydir_x;
	game_ptr->wallx -= (int)((game_ptr->wallx));
	game_ptr->tex_x = (int)(game_ptr->wallx * (double)(game_ptr->tex.width));
	if (game_ptr->side == 0 && game_ptr->raydir_x > 0)
		game_ptr->tex_x = game_ptr->tex.width - game_ptr->tex_x - 1;
	if (game_ptr->side == 1 && game_ptr->raydir_x < 0)
		game_ptr->tex_x = game_ptr->tex.width - game_ptr->tex_x - 1;
	game_ptr->tex_step = 1.0 * game_ptr->tex.height / game_ptr->line_height;
	game_ptr->tex_pos = (game_ptr->draw_start - game_ptr->screen_h \
		/ 2 + game_ptr->line_height / 2) * game_ptr->tex_step;
}

void	put_tex(t_program *game_ptr)
{
	int	color;
	int	y;

	y = game_ptr->draw_start;
	while (y < game_ptr->draw_end)
	{
		game_ptr->tex_y = (int)game_ptr->tex_pos & (game_ptr->tex.height - 1);
		game_ptr->tex_pos += game_ptr->tex_step;
		color = game_ptr->tex.arr[game_ptr->tex.height * game_ptr->tex_y \
			+ game_ptr->tex_x];
		if (game_ptr->side == 1)
			color = (color >> 1) & 8355711;
		game_ptr->img.arr[y * (game_ptr->screen_w) + (game_ptr->x)] = color;
		y++;
	}
}
