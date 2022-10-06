/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:28:01 by ccariou           #+#    #+#             */
/*   Updated: 2022/10/06 11:17:52 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 * Clean the previously allocated element if they exist
 */

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
	info->sum = OPP;
	info->elem = 0;
	info->s_row = 0;
	info->s_col = 0;
	info->b_row = 0;
	info->b_col = 0;
	info->check = 0;
	info->map = NULL;
	info->heatmap = NULL;
	return (1);
}

int	print_position(t_info *info, t_piece *piece)
{
	if (info->sum < PLAYER || info->sum >= OPP)
	{
		ft_printf("0 0\n");
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

/*
 * Loop as long as the game goes, set the info that need to get reset.
 * if return !=1 (== error) break the loop and clean exit
 */

void	play_the_game(t_info *info, t_piece *piece)
{
	while (1)
	{
		set_struct(info, piece);
		if (!((map_info(info)) == 1))
			break ;
		if (!((create_heat_map(info)) == 1))
			break ;
		if (!((piece_info(info, piece)) == 1))
			break ;
		set_position(info, piece);
		if (!((print_position(info, piece)) == 1))
			break ;
	}
	clean_exit(info, piece);
}

/* 
 * Initialize the two struct and get the info that would be static for every game.
 * then play the game by launching the while loop
 */

int	main(void)
{
	t_info	info;
	t_piece	piece;

	ft_bzero(&info, sizeof(t_info));
	ft_bzero(&piece, sizeof(t_piece));
	if (!((player_info(&info)) == 1))
		return (ERROR);
	if (!((get_map_dim(&info)) == 1))
		return (ERROR);
	play_the_game(&info, &piece);
	return (0);
}
