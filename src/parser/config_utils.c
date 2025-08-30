/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:47:37 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/30 16:17:22 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_digit_string(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int	all_configs_set(t_cub *cub)
{
	if (cub->map_set.no_path && cub->map_set.so_path
		&& cub->map_set.we_path && cub->map_set.ea_path
		&& cub->map_set.floor_color != -1
		&& cub->map_set.ceiling_color != -1)
		return (1);
	return (0);
}

void	trim_trailing_whitespace(char *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str) - 1;
	while (len >= 0 && ft_isspace(str[len]))
	{
		str[len] = '\0';
		len--;
	}
}
