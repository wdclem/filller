/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:07:05 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 16:37:11 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
/*
 * Check the information of the piece receive by the VM, s_col and s_row retain the starting point of the piece
 * (if piece start on second row, second col ect ect ...)
 */
void	shape_info(t_info *info, t_piece *piece, char *stdo, int i)
{
	int	j;

	while (++i < info->p_row)
	{
		get_next_line(0, &stdo);
		piece->shape[i] = ft_strdup(stdo);
		j = -1;
		while (++j < info->p_col)
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
}

int	piece_info(t_info *info, t_piece *piece)
{
	int		i;
	char	*stdo;

	i = 0;
	piece->shape = NULL;
	info->elem = 0;
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
	info->p_row = ft_atoi(&stdo[i]);
	while (ft_isdigit(stdo[i]))
		i++;
	info->p_col = ft_atoi(&stdo[i]);
	piece->shape = (char **)malloc(sizeof(char *) * info->p_row);
	i = -1;
	shape_info(info, piece, stdo, i);
	fprintf(stderr, "piece = %s\n", piece->shape[0]);
	return (1);
}
