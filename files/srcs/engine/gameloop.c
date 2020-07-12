/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-t <mmateo-t@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:01:42 by mmateo-t          #+#    #+#             */
/*   Updated: 2020/07/12 23:37:38 by mmateo-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void destroy_create_image(t_engine *en)
{
	mlx_destroy_image(en->mlx.ptr, en->mlx.img.ptr);
	en->mlx.img.ptr = mlx_new_image(en->mlx.ptr, g_config.R.x, g_config.R.y);
	en->mlx.img.data = (int*)mlx_get_data_addr(en->mlx.img.ptr, &en->mlx.img.bpp, &en->mlx.img.endian, &en->mlx.img.size_line);
}

int gameloop(t_engine *en)
{
	char *fps;
	
	movement(en);
	floor_casting(en);
	raycasting(en);
	fps = get_time(en);
	mlx_put_image_to_window(en->mlx.ptr, en->mlx.win, en->mlx.img.ptr, 0, 0);
	mlx_string_put(en->mlx.ptr, en->mlx.win, 20, 20, rgb_int(255, 255, 255), fps);
	destroy_create_image(en);
	usleep(10000);
	return (0);
}

