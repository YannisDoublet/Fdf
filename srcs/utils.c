/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:22:25 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/20 18:28:37 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		ft_count(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && (str[i + 1] == ' ' ||
			!str[i + 1]))
			j++;
		i++;
	}
	return (j);
}

int		ft_count_longest_line(t_ligne *head, t_stc *stc)
{
	t_ligne *current;

	current = head;
	stc->map.width = 0;
	while (current)
	{
		if (stc->map.width < ft_count(current->str))
			stc->map.width = ft_count(current->str);
		current = current->next;
	}
	return (stc->map.width);
}

void	ft_fill_tab(t_ligne *current, t_stc *stc, int y)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (current->str[i])
	{
		stc->map.tab[y][x].height = ft_atoi(current->str + i);
		while (ft_isdigit(current->str[i]) || current->str[i] == '-')
			i++;
		while (!(ft_isdigit(current->str[i])) && current->str[i] &&
			current->str[i] != '-')
			i++;
		if (current->str[i] == '0' && current->str[i + 1] == 'x')
		{
			stc->map.tab[y][x].color = ft_atoi_base(current->str + (i + 2),
			"0123456789ABCDEF");
			while (!(current->str[i - 1] == ' ' && ft_isdigit(current->str[i])))
				i++;
		}
		else
			stc->map.tab[y][x].color = 0;
		x++;
	}
}

int		ft_create_tab(t_ligne *head, t_stc *stc)
{
	int		y;
	t_ligne	*current;

	y = 0;
	current = head;
	stc->map.width = ft_count_longest_line(head, stc);
	if (!(stc->map.tab = ft_memalloc(sizeof(t_point **) *
		(stc->map.height + 1))))
		return (-1);
	while (current)
	{
		if (!(stc->map.tab[y] = ft_memalloc(sizeof(t_point *) *
			(stc->map.width))))
			return (-1);
		ft_fill_tab(current, stc, y);
		y++;
		current = current->next;
	}
	stc->map.tab[y] = NULL;
	return (0);
}
