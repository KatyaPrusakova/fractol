/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:38:41 by eprusako          #+#    #+#             */
/*   Updated: 2023/06/23 17:54:28 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FRACTOL_H
# define FRACTOL_H


# include <stdio.h>
// # include <stdlib.h>
// # include <fcntl.h>
# include "libmlx/includes/mlx.h"
# include "libft/libft.h"

#define WIN_WIDTH  1600
#define WIN_HEIGHT  1000
#define MLX_ERROR 1
#define MAX_ITERATION 50

// maybe not needed 
// #define IMAGENARY_FACTOR 1
// #define RealFactor (max_re - min_re)/(WIN_WIDTH-1);

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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_pix
{
	int	x;
	int	y;
	int width;
	int height;
	int color;

	long double min_real; // minimum real number 
	long double max_real; // maximum real number
	long double max_im; // maximum imaginary number
	long double min_im; // minimum imaginary number
	long double c_im; // minimum imaginary number
	long double c_real; // minimum imaginary number

    int z;
    int c;
    int n;
    int p;
	
}	t_pix;



typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	t_pix  obj;
}	t_data;



t_pix	init_pix_struct(void);
int	    handle_keypress(int keysym, t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
int	    render(t_data *data);
int is_in_set(long double z_real, long double z_im, t_pix *obj);


#endif