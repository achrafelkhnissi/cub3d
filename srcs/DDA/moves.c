/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:33:45 by fathjami          #+#    #+#             */
/*   Updated: 2022/06/27 21:22:23 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_program *game_ptr, double angle)
{
	double	olddirx;
	double	oldplanx;

	oldplanx = game_ptr->plane_x;
	olddirx = game_ptr->dir_x;
	game_ptr->dir_x = game_ptr->dir_x * cos(angle) - \
		game_ptr->dir_y * sin(angle);
	game_ptr->dir_y = olddirx * sin(angle) + game_ptr->dir_y * cos(angle);
	game_ptr->plane_x = game_ptr->plane_x * cos(angle) - \
		game_ptr->plane_y * sin(angle);
	game_ptr->plane_y = oldplanx * sin(angle) + game_ptr->plane_y * cos (angle);
}

void	forword(t_program *game_ptr)
{
	if (game_ptr->map.map[(int)(game_ptr->pos_x + game_ptr->dir_x)][(int)(\
		game_ptr->pos_y + game_ptr->dir_y)] == '0')
	{
		game_ptr->pos_x += game_ptr->dir_x * game_ptr->m_speed;
		game_ptr->pos_y += game_ptr->dir_y * game_ptr->m_speed;
	}
}

void	backword(t_program *game_ptr)
{
	if (game_ptr->map.map[(int)(game_ptr->pos_x - game_ptr->dir_x)][(int)(\
		game_ptr->pos_y - game_ptr->dir_y)] == '0')
	{
		game_ptr->pos_x -= game_ptr->dir_x * game_ptr->m_speed;
		game_ptr->pos_y -= game_ptr->dir_y * game_ptr->m_speed;
	}
}

void	right(t_program *game_ptr)
{
	if (game_ptr->map.map[(int)(game_ptr->pos_x)][(int)(\
		game_ptr->pos_y + game_ptr->dir_y + game_ptr->plane_y)] == '0')
	{
		game_ptr->pos_y += game_ptr->plane_y * game_ptr->m_speed;
		game_ptr->pos_x += game_ptr->plane_x * game_ptr->m_speed;
	}
}

void	left(t_program *game_ptr)
{
	if (game_ptr->map.map[(int)(game_ptr->pos_x)][(int)(\
		game_ptr->pos_y + game_ptr->dir_y - game_ptr->plane_y)] == '0')
	{
		game_ptr->pos_y -= game_ptr->plane_y * game_ptr->m_speed;
		game_ptr->pos_x -= game_ptr->plane_x * game_ptr->m_speed;
	}
}
