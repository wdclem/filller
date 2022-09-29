/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:48:15 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 18:57:22 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	player_info(t_info *info)
{
	int		player;
	char	*stdo;

	stdo = NULL;
	if (get_next_line(0, &stdo) < 1)
		return(0);
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
		return(0);
	while (!ft_isdigit(stdo[i]))
		i++;
	info->row  = ft_atoi(&stdo[i]);
	while (ft_isdigit(stdo[i]))
		i++;
	info->col = ft_atoi(&stdo[i]);
	ft_strdel(&stdo);
	return (1);
}

static void	get_map(t_info *info, char *stdo, int i, int j)
{
	while (++i < info->row)
	{
		j = -1;
		if (!(info->map[i]= ft_strdup(stdo + 4)))
		{
			clean_exit(info->map, info->row);
			return (0);
		}
		while (++j < info->col)
		{
			if (info->map[i][j] == info->enemy) 
				info->heatmap[i][j] = ENEMY;
			else if (info->map[i][j] == info->player) 
				info->heatmap[i][j] = PLAYER;
			else
				info->heatmap[i][j] = EMPTY;
		}
		if ((i + 1) < info->row)
			if (get_next_line(0, &stdo) < 1)
			{
				clean_exit(info->map, info->row);
				return (0);
			}
	}
	ft_strdel(&stdo);
}

int	map_info(t_info *info)
{
	int		i;
	int		j;
	char	*stdo;

	stdo = NULL;
	if (get_next_line(0, &stdo) < 1)
		return (0);
	while (ft_strncmp(stdo, "000 ", 4) != 0)
	{
		ft_strdel(&stdo);
		if (get_next_line(0, &stdo) < 1)
			return (0);
	}
	if (!(info->map = (char **)malloc(sizeof(char *) * info->row)))
		return (0);
	i = -1;
	j = -1;
	get_map(info, stdo, i, j);
	/*
	while (y < info->row)
	{
		x = 0;
		if ((info->map[y]= ft_strdup(stdo + 4)) == NULL)
			exit (1);
		while (x < info->col)
		{
			if (info->map[y][x] == info->enemy) 
			{
				info->heatmap[y][x] = ENEMY;
			}
			else if (info->map[y][x] == info->player) 
				info->heatmap[y][x] = PLAYER;
			else
			{
				info->heatmap[y][x] = EMPTY;
			}
			x++;
		}
		if ((y + 1) < info->row)
			get_next_line(0, &stdo);
		y++;
	}
	ft_strdel(&stdo);
	*/
	return (1);
}
