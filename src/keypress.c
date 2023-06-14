/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:25:48 by eprusako          #+#    #+#             */
/*   Updated: 2023/06/14 13:13:52 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	handle_keypress(int keysym, t_data *data)
{
    printf("%i keysym\n", keysym);
	if (keysym == ESC)
	{ 
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
    if (keysym == RIGHT && data->obj.x < WIN_WIDTH)
	{
		// data->rect.height -= 10;
		// data->rect.width += 10;
		// data->rect.y += 100;
		data->obj.x += 10;
		render(data);	
	}
	 if (keysym == LEFT  && data->obj.x > 10 )
	{
		// data->rect.height += 10;
		// data->rect.width -= 10;
		// data->rect.y += 100;
		data->obj.x -= 10;
		render(data);	
	}
	 if (keysym == UP && data->obj.y > 10)
	{
		// data->rect.height -= 10;
		// data->rect.width += 100;
		data->obj.y -= 10;
		// data->rect.x += 100;
		render(data);	
	}
	 if (keysym == DOWN && data->obj.y < WIN_HEIGHT)
	{
		// data->rect.height += 10;
		// data->rect.width += 100;
		data->obj.y += 10;
		// data->rect.x += 100;
		render(data);	
	}
	return (0);
}


