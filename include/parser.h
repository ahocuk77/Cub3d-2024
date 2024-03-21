/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:23:01 by musenov           #+#    #+#             */
/*   Updated: 2024/03/21 19:26:39 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "common.h"
# include "get_next_line.h"

void	parser(t_game *game, int fd);
void	p_texture(t_game *game, int fd);
char	*trimreplace(char *str, char *set);
void	p_color(t_game *game, int fd);
char	**ft_split_custom(char *s);
void	p_map(t_game *game, int fd);
void	map_check(t_game *game);
int		horizontal_check(t_game *game);
int		vertical_check(t_game *game);

#endif
