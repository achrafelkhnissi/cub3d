/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:39:12 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/04 14:05:03 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

typedef struct s_program
{
	void		*mlx;
	void		*win_ptr;
	void		*img_ptr;
	// int			img_size;
	// t_map		map;
	int			fd;
	int			can_exit;
}				t_program;

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

#define screenWidth 640
#define screenHeight 480


void	ft_new_window(t_program *game)
{
	game->win_ptr = mlx_new_window(game->mlx, screenWidth, screenHeight, "cub3D");
	mlx_hook(game->win_ptr, WIN_CLOSE, 0, ft_close, game);
}

int rgbToInt(int r, int g, int b) {
    return (r << 16) | (g << 8) | b;
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
			mlx_pixel_put(game.mlx, game.win_ptr, y++, i, rgbToInt(105, 105, 105));
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
			mlx_pixel_put(game.mlx, game.win_ptr, y++, i, rgbToInt(192, 192, 192));
		i++;
	}
}

int	main(void)
{
	t_program gamePtr;

	gamePtr.mlx = mlx_init();
	ft_new_window(&gamePtr);
	drawCeiling(gamePtr);
	drawFloor(gamePtr);
	mlx_loop(gamePtr.mlx);
	return (0);
}
