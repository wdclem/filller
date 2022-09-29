/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:51:51 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 17:46:33 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int	try_positions(t_info *info, t_piece *piece, int row, int col)
{
	int	ret;
	int	i;
	int	j;
	int y;
	int x;

	ret = 0;
	y = row;
	i = -1;
	while (++i < info->p_row)
	{
		x = col;
		j = -1;
		while (++j < info->p_col)
		{
			if (piece->shape[i][j] == '*')
				ret += (info->heatmap[y][x]);
			x++;
		}
		y++;
	}
	if (ret < PLAYER)
		return(ret = ENEMY);
	else
		return(ret);
}

/*
static void	save_best_position(t_info *info, int b_row, int b_col)
{
	info->b_row = b_row;
	info->b_col = b_col;
	return (info);
}
*/
int	set_position(t_info *info, t_piece *piece)
{
	int		ret;
	int		col;
	int		row;

	info->sum = ENEMY;
	row = -1;
	info->row -= info->p_row;
	info->col -= info->p_col;
	while (++row <= info->row)
	{
		col = -1;
		while (++col <= info->col)
		{
			ret = try_positions(info, piece, row, col);
			if (ret < info->sum || (ret == info->sum && col < info->b_col))
			{
				info->sum = ret;
				info->b_col = col;
				info->b_row = row;
			}
		}
	}
	return (1);
}
