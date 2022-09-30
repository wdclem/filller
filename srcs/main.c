/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:28:01 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/30 14:40:31 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//la bite de raoul est abberante

#include <stdio.h>
#include "../includes/filler.h"

/*void	clean_exit(int **array, int len)
{
	int	i;

	i = 0;
	while(i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
*/
int	clean_exit(t_info *info, t_piece *piece)
{
	if (info)
	{
		if(info->map)
			ft_freearray((void **)info->map, info->row);
		if(info->heatmap)
			ft_freearray((void **)info->heatmap, info->row);
		free(info);
		info = NULL;
	}
	if (piece)
	{
		if (piece->shape)
			ft_freearray((void **)piece->shape, piece->row);
		free(piece);
		piece = NULL;
	}
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
	info->map = NULL;
	info->heatmap = NULL;
	
	return (1);
}

int	print_position(t_info *info)
{
	if (info->sum < PLAYER || info->sum >= ENEMY)
	{
		ft_printf("0 0\n");
		return (-3);
	}
	else
		ft_printf("%d %d\n", info->b_row, info->b_col);
	return (1);
}

void	play_the_game(t_info *info, t_piece *piece)
{
	while(1)
	{
		set_struct(info, piece);
		if (!(map_info(info)))
			break ;
		if (!(create_heat_map(info)))
			break ;
		if (!(piece_info(info, piece)))
			break ;
		set_position(info, piece);
		if(!(print_position(info)))
			break;
	}
	fprintf(stderr,"maite la culotte");
	clean_exit(info, piece);
}

int	main(void)
{
	t_info	*info;
	t_piece	*piece;

	piece = NULL;
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (clean_exit(info, piece), -1);
	piece = (t_piece*)malloc(sizeof(t_piece));
	if (!piece)
		return (clean_exit(info, piece), -1);
	player_info(info);
	get_map_dim(info);
	play_the_game(info, piece);
	return (0);
}

