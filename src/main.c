/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:25:48 by eprusako          #+#    #+#             */
/*   Updated: 2023/05/23 17:41:02 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
	t_rect  rect;
}	t_data;


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

/* The x and y coordinates of the rect corresponds to its upper left corner. */

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	// printf("%i h\n%i w\n ", data->rect.height,  data->rect.width);
	
	render_rect(&data->img, data->rect);
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
    printf("%i keysym\n", keysym);
	if (keysym == ESC)
	{ 
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
    if (keysym == RIGHT && data->rect.x < WIN_WIDTH)
	{
		// data->rect.height -= 10;
		// data->rect.width += 10;
		// data->rect.y += 100;
		data->rect.x += 10;
		render(data);	
	}
	 if (keysym == LEFT  && data->rect.x > 10 )
	{
		// data->rect.height += 10;
		// data->rect.width -= 10;
		// data->rect.y += 100;
		data->rect.x -= 10;
		render(data);	
	}
	 if (keysym == UP && data->rect.y > 10)
	{
		// data->rect.height -= 10;
		// data->rect.width += 100;
		data->rect.y -= 10;
		// data->rect.x += 100;
		render(data);	
	}
	 if (keysym == DOWN && data->rect.y < WIN_HEIGHT)
	{
		// data->rect.height += 10;
		// data->rect.width += 100;
		data->rect.y += 10;
		// data->rect.x += 100;
		render(data);	
	}
	return (0);
}



t_rect	init_rect(void)
{
	t_rect rect_start;
	
	rect_start.color = GREEN_PIXEL;
	rect_start.height = 10;
	rect_start.width = 10;
	rect_start.x = 100;
	rect_start.y = 100;
	return rect_start; 
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	data.rect = init_rect();
	/* Setup hooks */ 

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 1L<<0, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	// mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}