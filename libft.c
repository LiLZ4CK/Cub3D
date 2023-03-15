/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:19:32 by zwalad            #+#    #+#             */
/*   Updated: 2023/01/05 02:36:18 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub1d.h"

int	*ft_aatoi(char *str, int i, int j)
{
	int	*arr;
	int	n;

	arr = malloc(sizeof(int) * 3);
	while (str[i] && str[i] != '\n')
	{
		n = 0;
		if (ft_isalnum(str[i]))
		{
			while (ft_isalnum(str[i]))
				n = (n * 10) + str[i++] - '0';
			if (j == 3 || n > 255)
				ft_error("exceed limit :");
			arr[j++] = n;
		}
		else
			ft_error("only numbers");
		if (str[i] == ',')
			i++;
	}
	if (j != 3)
		ft_error("3 colors needed !");
	return (arr);
}

static int	ft_wnb(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[0] != c && i == 0) || (str[i] != c && str[i - 1] == c))
		{
			i++;
			j++;
		}
		if (str[i])
			i++;
	}
	return (j);
}

static void	ft_free(char **str, int wnbr)
{
	int	i;

	i = 0;
	while (i < wnbr)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	alloc(char **sp, const char *s, char c, int wnbr)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	while (j < wnbr - 1)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
			index = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		sp [j] = ft_substr(s, index, i - index);
		if (!sp[j])
		{
			ft_free(sp, j);
			break ;
		}
		j++;
	}
	sp[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		wnbr;

	if (s == NULL)
		return (NULL);
	wnbr = ft_wnb(s, c) + 1;
	str = malloc(sizeof(char *) * wnbr);
	if (str == NULL)
		return (NULL);
	alloc(str, s, c, wnbr);
	return (str);
}
