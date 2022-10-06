/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:51:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/10/06 10:22:40 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# define OPP 20000
# define PLAYER 10000
# define EMPTY 100 
# define MALLOC_ERR -1 
# define GNL_ERR -2
# define ERROR -3

/* Struct to keep miscelanous infos */
typedef struct s_info{
	char	player;
	char	opp;
	int		col;
	int		row;
	int		elem;
	int		s_row;
	int		s_col;
	int		b_row;
	int		b_col;
	int		sum;
	int		check;
	char	**map;
	int		**heatmap;
}				t_info;

/* Struct to keep piece*/
typedef struct s_piece
{
	int		row;
	int		col;
	char	**shape;
}			t_piece;

int		main(void);
int		player_info(t_info *info);
int		get_map_dim(t_info *info);
int		map_info(t_info *info);
int		piece_info(t_info *info, t_piece *piece);
int		create_heat_map(t_info *info);
void	set_position(t_info *info, t_piece *piece);

#endif
