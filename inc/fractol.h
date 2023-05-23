/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:38:41 by eprusako          #+#    #+#             */
/*   Updated: 2023/05/23 17:36:51 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FRACTOL_H
# define FRACTOL_H


# include <stdio.h>
// # include <stdlib.h>
// # include <fcntl.h>
# include <mlx.h>

# include "libft/libft.h"

#define WIN_WIDTH  1000
#define WIN_HEIGHT  600
#define MLX_ERROR 1

// colors
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

// keyboard
#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

int     init_fractol(void);

#endif