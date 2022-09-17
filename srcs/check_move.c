/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:45:08 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/16 13:20:50 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	save_map
/*
 * check if cell is enemy, return true
 * REPLACE WITH ENEMY FOUND WHEN PLAYER FOUND
int	check_enemy(t_info *info, int x, int y)
{
	char	enemy;

	if (info->player == 'x')
		enemy = 'o';
	else
		enemy = 'x';
	return(1)
}
*/		
/*
 * check cells give them value if they are occupy by enemy, yours or empty
 */
int	check_cells(t_info *info)
{
	int	x;
	int	y;

	while (y <= piece->map[y])
	{
		x = 0;
		while (x <=piece->map[y][x])
			{
			if (check_enemy(info, y, x))
				info.map[y][x] = 0;
			else if (ft_tolower(info.map[y][x]) == info.player)
				info.map[y][x] = 5;
			else
				info.map[y][x] = 1;
			x++;
		}
		y++;
	}
	save_map(info);
	return(0);
}

