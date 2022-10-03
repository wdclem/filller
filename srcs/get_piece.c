/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:07:05 by ccariou           #+#    #+#             */
/*   Updated: 2022/10/03 12:36:40 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
 * Check the information of the piece receive by the VM
 * s_col and s_row retain the starting point of the piece
 * (if piece start on second row, second col ect ect ...)
 */

static void	start_point(t_info *info, t_piece *piece, int i, int j)
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

int	shape_info(t_info *info, t_piece *piece, int i)
{
	int		j;
	char	*stdo;

	stdo = NULL;
	while (++i < piece->row)
	{
		if (get_next_line(0, &stdo) < 1)
			return (-2);
		piece->shape[i] = ft_strdup(stdo);
		ft_strdel(&stdo);
		if (!piece->shape[i])
			return (-1);
		j = -1;
		while (++j < piece->col)
			start_point(info, piece, i, j);
	}
	return (1);
}

int	piece_info(t_info *info, t_piece *piece)
{
	int		i;
	char	*stdo;

	i = 0;
	stdo = NULL;
	if (get_next_line(0, &stdo) < 1)
		return (-2);
	while (ft_strncmp(stdo, "Piece", 5) != 0)
	{
		ft_strdel(&stdo);
		if (get_next_line(0, &stdo) < 1)
			return (-2);
	}
	while (!ft_isdigit(stdo[i]))
		i++;
	piece->row = ft_atoi(&stdo[i]);
	while (ft_isdigit(stdo[i]))
		i++;
	piece->col = ft_atoi(&stdo[i]);
	ft_strdel(&stdo);
	piece->shape = (char **)malloc(sizeof(char *) * piece->row);
	if (!piece->shape)
		return (-1);
	i = -1;
	return (shape_info(info, piece, i));
}
