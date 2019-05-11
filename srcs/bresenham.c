/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 18:54:00 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/20 20:14:16 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_init_bres(t_bres *bres, t_pos *pos)
{
	bres->ex = abs(pos->xfin - pos->xinit);
	bres->ey = abs(pos->yfin - pos->yinit);
	bres->dx = 2 * bres->ex;
	bres->dy = 2 * bres->ey;
	bres->x = bres->ex;
	bres->y = bres->ey;
	bres->i = 0;
	bres->xincr = ((pos->xinit > pos->xfin) ? -1 : 1);
	bres->yincr = ((pos->yinit > pos->yfin) ? -1 : 1);
}

void	ft_bresenham_line_up(t_bres bres, t_pos *pos, t_stc *stc)
{
	while (bres.i < bres.y)
	{
		bres.i++;
		pos->yinit += bres.yincr;
		bres.ey -= bres.dx;
		if (bres.ey < 0)
		{
			pos->xinit += bres.xincr;
			bres.ey += bres.dy;
		}
		mlx_pixel_put_to_image(stc, pos->xinit, pos->yinit,
		stc->map.color - stc->map.color_bonus);
	}
}

void	ft_bresenham_line_down(t_pos *pos, t_stc *stc)
{
	t_bres		bres;

	ft_init_bres(&bres, pos);
	if (bres.x > bres.y)
		while (bres.i < bres.x)
		{
			bres.i++;
			pos->xinit += bres.xincr;
			bres.ex -= bres.dy;
			if (bres.ex < 0)
			{
				pos->yinit += bres.yincr;
				bres.ex += bres.dx;
			}
			mlx_pixel_put_to_image(stc, pos->xinit, pos->yinit,
			stc->map.color + stc->map.color_bonus);
		}
	else
		ft_bresenham_line_up(bres, pos, stc);
}

t_pos	*ft_get_x_positions(t_stc *stc, int x, int y)
{
	t_pos		*pos;

	if (!(pos = ft_memalloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = stc->map.posx[y][x] - stc->map.tab[y][x].height
	* (stc->map.y_ecart / 50) * stc->map.alt + stc->map.vrt;
	pos->yinit = stc->map.posy[y][x] - stc->map.tab[y][x].height
	* (stc->map.y_ecart / 50) * stc->map.alt - stc->map.hzt;
	pos->xfin = stc->map.posx[y][x - 1] - stc->map.tab[y][x - 1].height
	* (stc->map.y_ecart / 50) * stc->map.alt + stc->map.vrt;
	pos->yfin = stc->map.posy[y][x - 1] - stc->map.tab[y][x - 1].height
	* (stc->map.y_ecart / 50) * stc->map.alt - stc->map.hzt;
	pos->xinit = (pos->xinit - pos->yinit) / 2;
	pos->yinit = (pos->xinit + pos->yinit) / 2;
	pos->xfin = (pos->xfin - pos->yfin) / 2;
	pos->yfin = (pos->xfin + pos->yfin) / 2;
	return (pos);
}

t_pos	*ft_get_y_positions(t_stc *stc, int x, int y)
{
	t_pos		*pos;

	if (!(pos = ft_memalloc(sizeof(t_pos))))
		return (NULL);
	pos->xinit = stc->map.posx[y][x] - stc->map.tab[y][x].height
	* (stc->map.y_ecart / 50) * stc->map.alt + stc->map.vrt;
	pos->yinit = stc->map.posy[y][x] - stc->map.tab[y][x].height
	* (stc->map.y_ecart / 50) * stc->map.alt - stc->map.hzt;
	pos->xfin = stc->map.posx[y - 1][x] - stc->map.tab[y - 1][x].height
	* (stc->map.y_ecart / 50) * stc->map.alt + stc->map.vrt;
	pos->yfin = stc->map.posy[y - 1][x] - stc->map.tab[y - 1][x].height
	* (stc->map.y_ecart / 50) * stc->map.alt - stc->map.hzt;
	pos->xinit = (pos->xinit - pos->yinit) / 2;
	pos->yinit = (pos->xinit + pos->yinit) / 2;
	pos->xfin = (pos->xfin - pos->yfin) / 2;
	pos->yfin = (pos->xfin + pos->yfin) / 2;
	return (pos);
}
