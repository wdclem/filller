/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:18:40 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/27 18:23:09 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/* take the address oof a string that need to be freed,
 *  free it and sets its pointer to NULL */

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	if (*as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
