/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:04:43 by fathjami          #+#    #+#             */
/*   Updated: 2022/06/27 21:27:30 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_program *game_ptr)
{
	int	i;

	i = -1;
	while (++i < game_ptr->draw_start)
		game_ptr->img.arr[i * game_ptr->screen_w + game_ptr->x] = \
		rgb_to_int(game_ptr->map.ceilling_color);
	i = game_ptr->draw_end;
	while (++i < game_ptr->screen_h)
		game_ptr->img.arr[i * game_ptr->screen_w + game_ptr->x] = \
		rgb_to_int(game_ptr->map.floor_color);
}

void	draw(t_program *game_ptr)
{
	while (game_ptr->x < game_ptr->screen_w)
	{
		init_draw_var(game_ptr);
		raycast(game_ptr);
		calc_distance(game_ptr);
		draw_floor_ceiling(game_ptr);
		get_tex(game_ptr);
		init_tex(game_ptr);
		put_tex(game_ptr);
		game_ptr->x++;
	}
	mlx_put_image_to_window(game_ptr->mlx, game_ptr->win_ptr,
		game_ptr->img.ptr, 0, 0);
}
