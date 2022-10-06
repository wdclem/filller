/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:51:51 by ccariou           #+#    #+#             */
/*   Updated: 2022/10/06 11:04:20 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/* Take the piece and try every elem of it on the board
 * trying to find the smallest value
 * repeat for all position of the board
 */

int	try_positions(t_info *info, t_piece *piece, int row, int col)
{
	int	ret;
	int	i;
	int	j;
	int	y;
	int	x;

	ret = 0;
	y = row;
	i = -1;
	while (++i < piece->row)
	{
		x = col;
		j = -1;
		while (++j < piece->col)
		{
			if (piece->shape[i][j] == '*')
				ret += (info->heatmap[y][x]);
			x++;
		}
		y++;
	}
	if (ret < PLAYER)
		return (ret = OPP);
	else
		return (ret);
}

void	set_position(t_info *info, t_piece *piece)
{
	int		ret;
	int		col;
	int		row;
	int		map_col;
	int		map_row;

	info->b_col = info->col;
	row = -1;
	map_row = info->row - piece->row;
	map_col = info->col - piece->col;
	while (++row <= map_row)
	{
		col = -1;
		while (++col <= map_col)
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
}
