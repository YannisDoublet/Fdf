/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:39:40 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/20 20:45:49 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		main(int argc, char **argv)
{
	int		fd;
	t_stc	*stc;

	if (!(stc = ft_memalloc(sizeof(t_stc))))
		return (-1);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			if (ft_fdf(fd, stc) == -1)
			{
				ft_printf("Map Error !\n");
				return (0);
			}
			mlx_put_image_to_window(stc->mlx.mlx_ptr, stc->mlx.win_ptr,
			stc->mlx.img_ptr, 0, 0);
			mlx_loop(stc->mlx.mlx_ptr);
		}
		else
			ft_printf("Invalid File !\n");
	}
	else
		ft_printf("Usage : ./fdf [*.fdf]\n");
	return (0);
}
