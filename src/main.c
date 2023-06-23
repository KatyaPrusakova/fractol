/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:25:48 by eprusako          #+#    #+#             */
/*   Updated: 2023/06/23 17:54:01 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"



int mandelbrot(t_img *img, t_pix obj)
{
	int	x;
	int y;
	double factor_re;
	double factor_im;

	y = 0;
	x = 0;


	factor_re = (obj.max_real - obj.min_real) / (WIN_WIDTH);
	factor_im = (obj.max_im - obj.min_im) / (WIN_HEIGHT);
	
	// printf("%Lf c_im\n%Lf c_real\n", obj.c_im, obj.c_real);
	
	while (y < WIN_HEIGHT)
	{
		obj.c_im = obj.max_im - y * factor_im;
		x = 0;
		while(x < WIN_WIDTH ) {
			obj.c_real = obj.min_real + x * factor_re;
		
			if (is_in_set(obj.c_real, obj.c_im, &obj)) {

				obj.color = (x<<16)|(y<<8)|0;
				img_pix_put(img, x, y, obj.color);
			}
			x++;
		}
		y++;
	}
	return (0);
}


// TO DO: refactor to pass only obj struct to the function
int is_in_set(long double z_real, long double z_im, t_pix *obj)
{
	int	i;
	long double c_real;
	long double c_im;
	long double z_re2;
	long double z_im2;

	i = 0;
	c_real = z_real;
	c_im = z_im;
	// printf("%x color\n", obj->color);

	while (i < MAX_ITERATION)
	{
		z_re2 = z_real * z_real;
		z_im2 = z_im * z_im;
		if (z_im2 + z_re2 > 4) {
			return 0;
		}
		z_im = 2 * z_real * z_im + c_im;
		z_real = z_re2 - z_im2 + c_real;
		i++;
	}
	return 1;
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	// render_background(&data->img, WHITE_PIXEL);
	// render_rect(&data->img, data->rect);
	// printf("start\n");
	
	
	// mandelbrot(&data->img, data->obj);
	mandelbrot(&data->img, data->obj);

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, -1, -1, WIN_WIDTH, WIN_HEIGHT, "my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	data.obj = init_pix_struct();
	/* Setup hooks */ 

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, &handle_keypress, &data);
	// mlx_hook(data.win_ptr, 4, 0, mouse_pressed_hook, env);
	// mlx_hook(data.win_ptr, 5, 0, mouse_released_hook, env);
	// mlx_hook(data.win_ptr, 6, 0, mouse_moved_hook, env);

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	// mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}