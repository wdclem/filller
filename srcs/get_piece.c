/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:07:05 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/30 16:46:13 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
/*
 * Check the information of the piece receive by the VM, s_col and s_row retain the starting point of the piece
 * (if piece start on second row, second col ect ect ...)
 */
int	shape_info(t_info *info, t_piece *piece, char *stdo, int i)
{
	int	j;

	while (++i < piece->row)
	{
		if (get_next_line(0, &stdo) < 1)
			return (-2);
		piece->shape[i] = ft_strdup(stdo);
		if (!piece->shape[i])
			return (-1);
		j = -1;
		while (++j < piece->col)
		{
			if (piece->shape[i][j] == '*')
			{
				if (j < info->s_col)
					info->s_col = j;
				if (i < info->s_row)
					info->s_row = i;
				info->elem++;
			}
		}
		ft_strdel(&stdo);
	}
	return (0);
}

int	piece_info(t_info *info, t_piece *piece)
{
	int		i;
	char	*stdo;

	i = 0;
	piece->shape = NULL;
	stdo = NULL;
	get_next_line(0, &stdo);
	while (ft_strncmp(stdo, "Piece", 5) != 0)
	{
		ft_strdel(&stdo);
		if (get_next_line(0, &stdo) < 1)
			return (-1);
	}
	while (!ft_isdigit(stdo[i]))
		i++;
	piece->row = ft_atoi(&stdo[i]);
	while (ft_isdigit(stdo[i]))
		i++;
	piece->col = ft_atoi(&stdo[i]);
	piece->shape = (char **)malloc(sizeof(char *) * piece->row);
	if (!piece->shape)
		return (-1);
	i = -1;
	ft_strdel(&stdo);
	shape_info(info, piece, stdo, i);
	return (1);
}
