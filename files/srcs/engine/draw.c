/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:34:05 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/15 14:23:06 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(t_engine *en, int x)
{
	int i;
	
	i = 0;
	while (i < en->draw_start)
	{
		*(en->mlx.img.data + (i * g_config.R.x) + x) = g_config.C.rgb_int;
		i++;
	}
	while (i < en->draw_end)
	{
		en->tex.y = (int)en->tex.pos & (en->mlx.texture[en->tex.num].height - 1);
		en->tex.pos += en->tex.step;
		en->color = en->mlx.texture[en->tex.num].data[en->mlx.texture[en->tex.num].height * en->tex.y + en->tex.x];
		*(en->mlx.img.data + (i * g_config.R.x) + x) = en->color;
		i++;
	}
	while (i < g_config.R.y - 1)
	{
		*(en->mlx.img.data + (i * g_config.R.x) + x) = g_config.F.rgb_int;
		i++;
	}
}
