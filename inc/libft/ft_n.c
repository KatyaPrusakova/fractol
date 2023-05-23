/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 15:58:23 by ksuomala          #+#    #+#             */
/*   Updated: 2021/05/25 13:53:51 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_n(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, "\n", 1);
		i++;
	}
}
