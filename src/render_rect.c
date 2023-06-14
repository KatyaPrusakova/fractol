/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:25:48 by eprusako          #+#    #+#             */
/*   Updated: 2023/06/14 13:53:26 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../inc/fractol.h"

int render_rect(t_img *img, t_pix rect)
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

t_pix	init_rect(void)
{
	t_pix rect_start;
	
	rect_start.color = GREEN_PIXEL;
	rect_start.height = 10;
	rect_start.width = 10;
	rect_start.x = 100;
	rect_start.y = 100;

	rect_start.c = 10;
	rect_start.z = 0;
	rect_start.n = 0;
	rect_start.p = 10;
	return rect_start; 
}
