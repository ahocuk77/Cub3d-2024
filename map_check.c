/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:42:13 by ahocuk            #+#    #+#             */
/*   Updated: 2024/03/19 19:26:36 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void map_check(t_game *game)
{
	printf("String: %s\n", "mapcheck start");
	if(horizontal_check(game) == -1)
	{
		printf("String: %s\n", "horizontal_check error");
		exit(1);
	}
	printf("String: %s\n", "horizontal_check passed");
	if(vertical_check(game) == -1)
	{
		printf("String: %s\n", "vertical_check error");
		exit(1);
	}
}