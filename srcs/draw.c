/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:39:27 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/20 21:08:44 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mlx_pixel_put_to_image(t_stc *stc, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = stc->mlx.x_size * stc->mlx.y_size * stc->mlx.bpp / 8;
	if (x < 0 || y < 0 || y * stc->mlx.size_line
	+ x * stc->mlx.bpp / 8 > img_size || x >= stc->mlx.size_line /
	(stc->mlx.bpp / 8) || y >= img_size / stc->mlx.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = stc->mlx.bpp / 8;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix] = color1;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix + 1] = color2;
	stc->mlx.img_addr[y * stc->mlx.size_line + x * bit_pix + 2] = color3;
}

void	ft_draw_horizontal_lines(t_stc *stc, int x, int y)
{
	t_pos	*pos;

	if (y != 0)
	{
		if (stc->map.tab[y][x].color != 0)
			stc->map.color = stc->map.tab[y][x].color;
		else if (stc->map.tab[y][x].height < 0 || stc->map.tab[y][x].height
				== 0)
			stc->map.color = 0x00B9FF;
		else if (stc->map.tab[y][x].height > 0 && stc->map.tab[y][x].height
				<= 10)
			stc->map.color = 0x00FF66;
		else if (stc->map.tab[y][x].height > 10 && stc->map.tab[y][x].height
				<= 20)
			stc->map.color = 0xFEA021;
		else if (stc->map.tab[y][x].height > 20)
			stc->map.color = 0xA94F00;
		pos = ft_get_y_positions(stc, x, y);
		ft_bresenham_line_down(pos, stc);
		free(pos);
	}
}

void	ft_draw_vertical_lines(t_stc *stc, int x, int y)
{
	t_pos	*pos;

	if (x != 0)
	{
		if (stc->map.tab[y][x].color != 0)
			stc->map.color = stc->map.tab[y][x].color;
		else if (stc->map.tab[y][x].height < 0 || stc->map.tab[y][x].height
				== 0)
			stc->map.color = 0x00B9FF;
		else if (stc->map.tab[y][x].height > 0 && stc->map.tab[y][x].height
				<= 10)
			stc->map.color = 0x00FF66;
		else if (stc->map.tab[y][x].height > 10 && stc->map.tab[y][x].height
				<= 20)
			stc->map.color = 0xFEA021;
		else if (stc->map.tab[y][x].height > 20)
			stc->map.color = 0xA94F00;
		pos = ft_get_x_positions(stc, x, y);
		ft_bresenham_line_down(pos, stc);
		free(pos);
	}
}

int		ft_draw(t_stc *stc)
{
	int		x;
	int		y;

	y = 0;
	if (ft_allocate_pos_tab(stc) == -1)
		return (-1);
	stc->map.pad_y = ((stc->mlx.y_size / 3) * 2) / stc->map.height
	+ stc->map.zoom;
	stc->map.pad_x = ((stc->mlx.x_size / 3) * 2) / stc->map.width
	+ stc->map.zoom;
	while (y < stc->map.height)
	{
		x = 0;
		while (x < stc->map.width)
		{
			stc->map.posx[y][x] = x * stc->map.pad_x + stc->map.x_ecart;
			stc->map.posy[y][x] = y * stc->map.pad_y + stc->map.y_ecart;
			ft_draw_vertical_lines(stc, x, y);
			ft_draw_horizontal_lines(stc, x, y);
			x++;
		}
		y++;
	}
	ft_free_pos_tab(stc);
	return (0);
}
