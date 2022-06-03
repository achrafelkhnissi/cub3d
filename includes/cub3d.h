/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khni <ael-khni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:13:41 by ael-khni          #+#    #+#             */
/*   Updated: 2022/06/03 10:14:43 by ael-khni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include "mlx.h"

/* -------- KEY VALUES -------- */
# define RIGHT_KEY 2
# define LEFT_KEY 0
# define DOWN_KEY 1
# define UP_KEY 13
# define ESC_KEY 53
# define WIN_CLOSE 17

/* -------- MAP -------- */
# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 32

/* -------- COLORS -------- */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define END "\033[0m"

#endif
