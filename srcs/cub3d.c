/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fathjami <fathjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:39:12 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/08 16:19:06 by fathjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	ft_free(t_program *game, char *msg)
{
	int	i;

	i = 0;
	// while (game->map.map[i])
	// 	free(game->map.map[i++]);
	// free(game->map.map);
	mlx_destroy_window(game->mlx, game->win_ptr);
	printf("%s\n", msg);
	// if (ft_strcmp(msg, "BRAVO!") == 0)
	// 	printf("\n%s%s%s\n", GREEN,
	// 		"⊱ ──────────────── {.⋅ ✯ BRAVO! ✯ ⋅.} ───────────────── ⊰", END);
	// else
	// 	printf("\n%s%s%s\n", RED, msg, END);
	exit(EXIT_SUCCESS);
}


int	ft_close(t_program *game)
{
	ft_free(game, "WINDOW CLOSED");
	return (0);
}

void	ft_new_window(t_program *game)
{
	game->win_ptr = mlx_new_window(game->mlx, screenWidth, screenHeight, "cub3D");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	drawCeiling(t_program game)
{
	int	i;
	int	y;

	i = 0;
	while (i < screenHeight / 2)
	{
		y = 0;
		while (y < screenWidth)
			mlx_pixel_put(game.mlx, game.win_ptr, y++, i, rgb_to_int(105, 105, 105));
		i++;
	}
}

void	drawFloor(t_program game)
{
	int	i;
	int	y;

	i = (screenHeight / 2);
	while (i < screenHeight)
	{
		y = 0;
		while (y < screenWidth)
			mlx_pixel_put(game.mlx, game.win_ptr, y++, i, rgb_to_int(192, 192, 192));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_program game_ptr;

	(void) av;
	if (!ac)
		return (EXIT_FAILURE);
	// game_ptr.map.filename = ft_strdup(av[1]); // TODO: free
	// get_cub_content(&game_ptr);
	// print_map(game_ptr.cub_content);
	// get_colors(&game_ptr);
	// get_map(&game_ptr);
	// print_map(game_ptr.map.map);

	game_ptr.screen_h = 480;
	game_ptr.screen_w = 640;
	game_ptr.mlx = mlx_init();
	ft_new_window(&game_ptr);
	drawCeiling(game_ptr);
	drawFloor(game_ptr);
	// lunch_game(&game_ptr)÷;
	mlx_loop_hook(game_ptr.mlx, lunch_game, &game_ptr);
	mlx_loop(game_ptr.mlx);
	return (0);
}
