/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:25:48 by eprusako          #+#    #+#             */
/*   Updated: 2023/06/16 12:23:46 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


t_pix	init_pix_struct(void)
{
	t_pix data;
	
	data.color = GREEN_PIXEL;
	data.height = 700;
	data.width = 500;
	data.x = 1;
	data.y = 1;
	data.min_real = -2.0;
	data.max_real = 1.0;
	data.min_im = -1.2;
	data.max_im = 1.2;
	data.c_real = -2;
	data.c_im = -1.2;

	return data; 
}

