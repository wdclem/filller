/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:28:01 by ccariou           #+#    #+#             */
/*   Updated: 2022/10/03 11:49:03 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	clean_exit(t_info *info, t_piece *piece)
{
	if (info)
	{
		if (info->map != NULL)
			ft_freearray((void **)info->map, info->row);
		if (info->heatmap != NULL)
			ft_freearray((void **)info->heatmap, info->row);
	}
	if (piece)
	{
		if (piece->shape != NULL)
			ft_freearray((void **)piece->shape, piece->row);
	}
	if (info->check == 1)
		return (1);
	else
		return (0);
}

int	set_struct(t_info *info, t_piece *piece)
{
	piece->shape = NULL;
	piece->row = 0;
	piece->col = 0;
	info->sum = ENEMY;
	info->elem = 0;
	info->s_row = 90000;
	info->s_col = 90000;
	info->b_row = 0;
	info->b_col = 0;
	info->check = 0;
	info->map = NULL;
	info->heatmap = NULL;
	return (1);
}

int	print_position(t_info *info, t_piece *piece)
{
	if (info->sum < PLAYER || info->sum >= ENEMY)
	{
		write(1, "0 0\n", 4);
		return (0);
	}
	else
	{
		ft_printf("%d %d\n", info->b_row, info->b_col);
		info->check = 1;
		clean_exit(info, piece);
	}
	return (1);
}

void	play_the_game(t_info *info, t_piece *piece)
{
	while (1)
	{
		set_struct(info, piece);
		if (!(map_info(info)))
			break ;
		if (!(create_heat_map(info)))
			break ;
		if (!(piece_info(info, piece)))
			break ;
		set_position(info, piece);
		if (!(print_position(info, piece)))
			break ;
	}
	clean_exit(info, piece);
}

int	main(void)
{
	t_info	info;
	t_piece	piece;

	ft_bzero(&info, sizeof(t_info));
	ft_bzero(&piece, sizeof(t_piece));
	player_info(&info);
	get_map_dim(&info);
	play_the_game(&info, &piece);
	system ("leaks ccariou.filler >> filler.note");
	return (0);
}
