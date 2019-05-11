/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 20:36:49 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/20 20:56:56 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_window_instructions(t_win win)
{
	mlx_string_put(win.mlx_ptr, win.win_ptr, 0, 75,
	0xFFFFFF, "FDF COMMANDS :");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 150, 0,
	0xFFFFFF, "PRESS 1 OR 2 TO CHANGE COLORS");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 150, 25,
	0xFFFFFF, "PRESS + OR - TO INCREASE OR");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 150, 50,
	0xFFFFFF, "DECREASE ALTITUDE");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 150, 75,
	0xFFFFFF, "PRESS W  A  S  D TO MOVE");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 150, 100,
	0xFFFFFF, "PRESS R TO RESET");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 150, 125,
	0xFFFFFF, "USE MOUSE WHEEL UP AND MOUSE WHEEL DOWN");
	mlx_string_put(win.mlx_ptr, win.win_ptr, 150, 150,
	0xFFFFFF, "TO ZOOM IN AND OUT");
}

int		ft_window(void)
{
	t_win	win;

	win.mlx_ptr = mlx_init();
	win.x_size = 500;
	win.y_size = 175;
	win.win_ptr = mlx_new_window(win.mlx_ptr, win.x_size,
	win.y_size, "FDF COMMANDS");
	win.img_ptr = mlx_new_image(win.mlx_ptr, win.x_size,
	win.y_size);
	win.img_addr = mlx_get_data_addr(win.img_ptr, &win.bpp,
	&win.size_line, &win.endian);
	ft_window_instructions(win);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr,
	win.img_ptr, 0, 0);
	return (0);
}
