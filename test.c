/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprusako <eprusako@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:23:00 by eprusako          #+#    #+#             */
/*   Updated: 2023/06/14 19:21:03 by eprusako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/fractol.h"


int main(void)
{
    int b = 1;
    printf("%x\n", RED_PIXEL); 
    printf("%x\n", RED_PIXEL ^ b); 
    
}



// gcc -Wall -Wextra -Werror -Imlx -c test.c
// gcc -o test test.o -Lmlx -lmlx -framework OpenGL -framework AppKit