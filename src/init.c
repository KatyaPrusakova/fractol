/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:25:48 by eprusako          #+#    #+#             */
/*   Updated: 2023/06/14 13:12:30 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


t_pix	init_pix_struct(void)
{
	t_pix data;
	
	data.color = GREEN_PIXEL;
	data.height = 10;
	data.width = 10;
	data.x = 100;
	data.y = 100;

	data.p = 10;
	return data; 
}

