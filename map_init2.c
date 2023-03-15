/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:42:25 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/04 01:27:55 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

void	getl(t_big *p)
{
	free(p->line);
	p->line = NULL;
	p->line = get_next_line(p->fd);
}

void	get_contents(t_big *p)
{
	content_init(p);
	while (p->line && p->j != 6)
	{
		p->i = 0;
		while (p->line[p->i])
		{
			if ((p->line[p->i] == 'N' && p->line[p->i + 1] == 'O')
				|| (p->line[p->i] == 'S' && p->line[p->i + 1] == 'O')
				|| (p->line[p->i] == 'W' && p->line[p->i + 1] == 'E')
				|| (p->line[p->i] == 'E' && p->line[p->i + 1] == 'A')
				|| p->line[p->i] == 'F' || p->line[p->i] == 'C')
			{
				check_mfile2(p);
				break ;
			}
			else if (p->line[p->i] == ' ' || p->line[p->i] == '\t')
				p->i++;
			else if (p->line[p->i] == '\n' || !p->line[p->i])
				break ;
			else
				ft_error("wrong element !");
		}
		getl(p);
	}
	get_map(p);
}

void	check_map(t_big *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map.map[i])
	{
		j = 0;
		while (p->map.map[i][j])
		{
			if (p->map.map[i][j] != ' ' && p->map.map[i][j] != '1'
				&& p->map.map[i][j] != '0' && p->map.map[i][j] != 'E'
				&& p->map.map[i][j] != 'N' && p->map.map[i][j] != 'S'
				&& p->map.map[i][j] != 'W')
				ft_error("wrong map !");
			else
				j++;
		}
		i++;
	}
}

int	check_zerov2(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W')
		return (1);
	return (0);
}

void	check_texture(t_big *p)
{
	int	i;
	int	fds[4];

	check_path(p->content.north_p, ".xpm");
	check_path(p->content.south_p, ".xpm");
	check_path(p->content.east_p, ".xpm");
	check_path(p->content.west_p, ".xpm");
	fds[0] = open(p->content.north_p, O_RDONLY);
	fds[1] = open(p->content.south_p, O_RDONLY);
	fds[2] = open(p->content.east_p, O_RDONLY);
	fds[3] = open(p->content.west_p, O_RDONLY);
	i = 0;
	while (i < 4)
	{
		if (fds[i] == -1)
			ft_error("cant open textures file !");
		i++;
	}
}
