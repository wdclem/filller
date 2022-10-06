/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:41:30 by ccariou           #+#    #+#             */
/*   Updated: 2022/10/06 10:43:38 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/* Function places n byte null bytes in the string s
 * use to set all socket with null values>
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
