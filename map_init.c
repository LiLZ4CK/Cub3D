/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:40:31 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/06 00:14:14 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

void	check_mfile3(t_big *p, int i, char **side)
{
	(void)i;
	p->i += 2;
	if (p->line[p->i] != ' ' && p->line[p->i] != '\t')
		ft_error("wrong texture !");
	while (p->line[p->i] == ' ' || p->line[p->i] == '\t')
		p->i++;
	*side = ft_substr(p->line + p->i, 0, ft_strlen(p->line + p->i) - 1);
		p->j++;
}

void	check_mfile4(t_big *p, int i, int **side)
{
	(void)i;
	p->i++;
	if (p->line[p->i] != ' ' && p->line[p->i] != '\t')
		ft_error("wrong texture !");
	while (p->line[p->i] == ' ' || p->line[p->i] == '\t')
		p->i++;
	*side = ft_aatoi(p->line + p->i, 0, 0);
	p->j++;
}

void	check_mfile2(t_big *p)
{
	if (p->line[p->i] == 'N' && p->line[p->i + 1] == 'O')
		check_mfile3(p, p->content.no++, &p->content.north_p);
	else if (p->line[p->i] == 'S' && p->line[p->i + 1] == 'O')
		check_mfile3(p, p->content.so++, &p->content.south_p);
	else if (p->line[p->i] == 'W' && p->line[p->i + 1] == 'E')
		check_mfile3(p, p->content.we++, &p->content.west_p);
	else if (p->line[p->i] == 'E' && p->line[p->i + 1] == 'A')
		check_mfile3(p, p->content.ea++, &p->content.east_p);
	else if (p->line[p->i] == 'F')
		check_mfile4(p, p->content.f++, &p->content.fn);
	else if (p->line[p->i] == 'C')
		check_mfile4(p, p->content.c++, &p->content.cn);
}

void	get_map2(t_big *p)
{
	char	*map;

	map = ft_strdup("");
	while (p->line)
	{
		while (p->line && p->line[0] == '\n')
		{
			getl(p);
			if (p->line && ft_instr(p->line, '1'))
			{
				free(map);
				ft_error("wrong map !");
			}
		}
		if (p->line)
			map = ft_strjoin(map, p->line);
		getl(p);
	}
	p->map.map = ft_split(map, '\n');
	free(map);
}

void	get_map(t_big *p)
{
	if (p->content.no != 1 || p->content.so != 1 || p->content.we != 1
		|| p->content.ea != 1 || p->content.c != 1 || p->content.f != 1
		|| p->j != 6)
		ft_error("in elements !");
	if (!p->line)
		ft_error("where is your map ??");
	while (p->line[0] == '\n')
	{
		getl(p);
		if (!p->line)
			ft_error("where is your map ??");
	}
	get_map2(p);
}
