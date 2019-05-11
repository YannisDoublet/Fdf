/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:26:43 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/25 15:15:55 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_check_hexa(char *line, int i)
{
	int save;
	int	a;
	int	c;

	save = i;
	c = 0;
	if (line[i] == ',' && line[i - 1] >= '0' && line[i - 1] <= '9' &&
		line[i + 1] == '0' && line[i + 2] == 'x')
	{
		i += 3;
		a = i;
		while (line[a++] != ' ')
			c++;
		if (c != 6)
			return (0);
		while (ft_is_maj_hexa(line[i]) != -1)
			i++;
		return (i - save);
	}
	return (-1);
}

int		ft_check_fdf(char *line)
{
	int i;
	int	a;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			if ((a = ft_check_hexa(line, i)) < 0)
				return (-1);
			else
				i += a;
		}
		if ((line[i] >= '0' && line[i] <= '9') || (line[i] == '-' &&
			line[i + 1] >= '0' && line[i + 1] <= '9') || (line[i] == ' '))
			i++;
		else
			return (-1);
	}
	return (0);
}
