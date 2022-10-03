/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:48:15 by ccariou           #+#    #+#             */
/*   Updated: 2022/10/03 12:49:29 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int	player_info(t_info *info)
{
	int		player;
	char	*stdo;

	stdo = NULL;
	if (get_next_line(0, &stdo) < 1)
		return (-2);
	player = stdo[10] - '0';
	if (player == 1)
	{
		info->player = 'O';
		info->enemy = 'X';
	}
	else if (player == 2)
	{
		info->player = 'X';
		info->enemy = 'O';
	}
	ft_strdel(&stdo);
	return (1);
}

int	get_map_dim(t_info *info)
{
	char	*stdo;
	int		i;

	stdo = NULL;
	i = 0;
	if (get_next_line(0, &stdo) < 1)
		return (-2);
	while (!ft_isdigit(stdo[i]))
		i++;
	info->row = ft_atoi(&stdo[i]);
	while (ft_isdigit(stdo[i]))
		i++;
	info->col = ft_atoi(&stdo[i]);
	ft_strdel(&stdo);
	return (1);
}

static void	set_map(t_info *info, int i, int j)
{
	if (info->map[i][j] == info->enemy)
		info->heatmap[i][j] = ENEMY;
	else if (info->map[i][j] == info->player)
		info->heatmap[i][j] = PLAYER;
	else
		info->heatmap[i][j] = EMPTY;
}

static int	get_map(t_info *info, int i, int j)
{
	char	*stdo;

	if (get_next_line(0, &stdo) < 1)
		return (-2);
	while (++i < info->row)
	{
		j = -1;
		info->map[i] = ft_strdup(stdo + 4);
		ft_strdel(&stdo);
		info->heatmap[i] = (int *)malloc(sizeof(int) * info->col);
		if (!(info->map[i] || info->heatmap[i]))
			return (-1);
		while (++j < info->col)
			set_map(info, i, j);
		if ((i + 1) < info->row)
			if (get_next_line(0, &stdo) < 1)
				return (-2);
	}
	if (stdo)
		ft_strdel(&stdo);
	return (1);
}

int	map_info(t_info *info)
{
	int		i;
	int		j;
	char	*stdo;

	stdo = NULL;
	if (get_next_line(0, &stdo) < 1)
		return (-2);
	while (ft_strncmp(stdo, "    0123", 8) != 0)
	{
		ft_strdel(&stdo);
		if (get_next_line(0, &stdo) < 1)
			return (-2);
	}
	ft_strdel(&stdo);
	info->heatmap = (int **)malloc(sizeof(int *) * info->row);
	info->map = (char **)malloc(sizeof(char *) * info->row);
	if (!(info->map || info->heatmap))
		return (-1);
	i = -1;
	j = -1;
	if (!(get_map(info, i, j)))
		return (-1);
	return (1);
}
