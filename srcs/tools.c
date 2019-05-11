/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:14:30 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/20 20:04:03 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_stc_init(t_stc *stc)
{
	stc->mlx.mlx_ptr = mlx_init();
	stc->mlx.x_size = 800;
	stc->mlx.y_size = 800;
	stc->mlx.win_ptr = mlx_new_window(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size, "FDF");
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
	stc->map.x_ecart = ((stc->mlx.x_size / 3) * 2);
	stc->map.y_ecart = ((stc->mlx.y_size / 3) * 2);
}

void	ft_init_keycode(t_stc *stc)
{
	stc->map.hzt = stc->mlx.y_size / 2;
	stc->map.vrt = stc->mlx.x_size / 2;
	stc->map.alt = 1;
	stc->map.zoom = 1;
	stc->map.color_bonus = 0;
}

int		ft_mousehook(int button, int x, int y, t_stc *stc)
{
	(void)x;
	(void)y;
	if (button == MOUSE_UP)
		stc->map.zoom += 1;
	if (button == MOUSE_DOWN)
		stc->map.zoom -= 1;
	mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
	ft_draw(stc);
	mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
	stc->mlx.img_ptr, 0, 0);
	return (0);
}

int		ft_keycode2(int key, t_stc *stc)
{
	if (key == D)
	{
		stc->map.vrt += 10;
		stc->map.hzt += 10;
	}
	if (key == PLUS)
		stc->map.alt += 1;
	if (key == MINUS)
		stc->map.alt -= 1;
	if (key == RESET)
		ft_init_keycode(stc);
	if (key == ONE)
		stc->map.color_bonus += 100;
	if (key == TWO)
		stc->map.color_bonus -= 100;
	mlx_destroy_image(stc->mlx.mlx_ptr, stc->mlx.img_ptr);
	stc->mlx.img_ptr = mlx_new_image(stc->mlx.mlx_ptr, stc->mlx.x_size,
	stc->mlx.y_size);
	stc->mlx.img_addr = mlx_get_data_addr(stc->mlx.img_ptr, &stc->mlx.bpp,
	&stc->mlx.size_line, &stc->mlx.endian);
	ft_draw(stc);
	mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
	stc->mlx.img_ptr, 0, 0);
	return (0);
}

int		ft_keycode(int key, t_stc *stc)
{
	if (key == ESC)
		exit(1);
	if (key == W)
	{
		stc->map.vrt -= 10;
		stc->map.hzt += 10;
	}
	if (key == S)
	{
		stc->map.hzt -= 10;
		stc->map.vrt += 10;
	}
	if (key == A)
	{
		stc->map.vrt -= 10;
		stc->map.hzt -= 10;
	}
	ft_keycode2(key, stc);
	return (0);
}
