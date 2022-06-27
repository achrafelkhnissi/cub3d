/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:04:43 by fathjami          #+#    #+#             */
/*   Updated: 2022/06/27 18:25:21 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_floor_ceiling(t_program *game_ptr)
{
	int	i;

	i = -1;
	while(++i < game_ptr->draw_start)
		game_ptr->img.arr[i * game_ptr->screen_w + game_ptr->x] = rgb_to_int(game_ptr->map.ceilling_color);
	i = game_ptr->draw_end;
	while(++i < game_ptr->screen_h)
		game_ptr->img.arr[i * game_ptr->screen_w + game_ptr->x] = rgb_to_int(game_ptr->map.ceilling_color);
}