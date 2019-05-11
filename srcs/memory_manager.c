/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:27:39 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/20 20:49:57 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			ft_allocate_check(int i, t_ligne *head, t_stc *stc, char *line)
{
	if (i > 0)
	{
		free(line);
		ft_create_tab(head, stc);
		ft_free_chain_list(head);
	}
	else
		return (-1);
	return (0);
}

void		ft_free_pos_tab(t_stc *stc)
{
	int	i;

	i = 0;
	while (i < stc->map.height)
	{
		free(stc->map.posx[i]);
		free(stc->map.posy[i]);
		i++;
	}
	free(stc->map.posx);
	free(stc->map.posy);
}

void		ft_free_chain_list(t_ligne *head)
{
	t_ligne *tmp;

	while (head)
	{
		free(head->str);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int			ft_allocate_pos_tab(t_stc *stc)
{
	int		i;

	i = 0;
	if (!(stc->map.posx = ft_memalloc(sizeof(int **) * stc->map.height)))
		return (-1);
	if (!(stc->map.posy = ft_memalloc(sizeof(int **) * stc->map.height)))
		return (-1);
	while (i < stc->map.height)
	{
		if (!(stc->map.posx[i] = ft_memalloc(sizeof(int) * stc->map.width)))
			return (-1);
		if (!(stc->map.posy[i] = ft_memalloc(sizeof(int) * stc->map.width)))
			return (-1);
		i++;
	}
	return (0);
}
