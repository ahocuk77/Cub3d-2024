/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:20:43 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 19:18:43 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "parser.h"
# include "renderer.h"

int		main(int argc, char **argv);
int		parse_and_init(int argc, char **argv, t_game *game);

#endif
