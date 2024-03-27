/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 19:23:01 by musenov           #+#    #+#             */
/*   Updated: 2024/03/27 16:36:43 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

// # include "common.h"
# include "get_next_line.h"

void	parser(t_game *game, int fd);
void	p_texture(t_game *game, int fd);
char	*trimreplace(char *str, char *set);
void	p_color(t_game	*game, int fd);
char	**ft_split_custom(char *s);
void	p_map(t_game *game, int fd);
void	map_check(t_game *game);
int		horizontal_check(t_game *game);
int		vertical_check(t_game *game);
void	ft_init(t_game *game);
int		ft_cubcheck(char *map);
void	free_all(t_game *game);
int		is_numeric(char *str);
char	*handle_color_num_error(t_game *game, int j);
size_t	ft_strlen2(const char *s);
int		path_check(char *path);
int		len_checker(t_game *game, int x, int y);
int		len_checker2(t_game *game, int x, int y);

#endif
