/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:23:31 by fathjami          #+#    #+#             */
/*   Updated: 2022/06/27 18:59:42 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_program* game_ptr)
{
	mlx_destroy_image(game_ptr->mlx, game_ptr->img.ptr);
	game_ptr->img.ptr = mlx_new_image(game_ptr->mlx, game_ptr->screen_w, game_ptr->screen_h);
	if (game_ptr->r_right == 1)
		rotate(game_ptr, -(game_ptr->r_angle));
	else if (game_ptr->r_left == 1)
		rotate(game_ptr, game_ptr->r_angle);
	else if (game_ptr->m_up == 1)
		forword(game_ptr);
	else if (game_ptr->m_down == 1)
		backword(game_ptr);
	else if (game_ptr->m_right == 1)
		right(game_ptr);
	else if (game_ptr->m_left == 1)
		left(game_ptr);
	mlx_clear_window(game_ptr->mlx, game_ptr->win_ptr);
	game_ptr->x = 0;
	lunch_game(game_ptr);
}

int press(int key, t_program* game_ptr)
{
	if (key == RIGHT_R)
		game_ptr->r_right = 1;
	else if (key == LEFT_R)
		game_ptr->r_left = 1;
	else if (key == UP_M)
		game_ptr->m_up = 1;
	else if (key == DOWN_M)
		game_ptr->m_down = 1;
	else if (key == RIGHT_M)
		game_ptr->m_right = 1;
	else if (key == LEFT_M)
		game_ptr->m_left = 1;
	else if (key == ESC_KEY)
		ft_close(game_ptr);
	else
		return (1);
	move(game_ptr);
	return 0;
}

int release(int key, t_program* game_ptr)
{
	if (key == RIGHT_R)
		game_ptr->r_right = 0;
	else if (key == LEFT_R)
		game_ptr->r_left = 0;
	else if (key == UP_M)
		game_ptr->m_up = 0;
	else if (key == DOWN_M)
		game_ptr->m_down = 0;
	else if (key == RIGHT_M)
		game_ptr->m_right = 0;
	else if (key == LEFT_M)
		game_ptr->m_left = 0;
	return 0;
}