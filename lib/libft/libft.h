/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocuk <ahocuk@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:24:27 by ahocuk            #+#    #+#             */
/*   Updated: 2024/05/03 20:18:49 by ahocuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_split_next
{
	size_t	start;
	size_t	length;
}				t_split_next;

int				ft_atoi(const char *str);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t count, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

char			*ft_itoa(int n);

void			*ft_memchr(const void *ptr, int c, size_t n);

int				ft_memcmp(const void *ptr1, const void *ptr2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t n);

void			*ft_memset(void *b, int c, size_t len);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strchr(const char *s, int c);

char			*ft_strdup(const char *s1);

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);

void			ft_striteri(char *s, void ( *f)(unsigned int, char*));

size_t			ft_strlen(const char *s);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				ft_strncmp(const char *str1, const char *str2, size_t n);

char			*ft_strnstr(const char *str1, const char *str2,
					size_t len);

char			*ft_strrchr(const char *s, int c);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_tolower(int c);

int				ft_toupper(int c);

t_list			*ft_lstnew(void *content);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_front(t_list **lst, t_list *new);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstiter(t_list *lst, void (*f)(void*));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin_gnl(char const *s1, char const *s2);

int				read_to_buf(char **left, char **line, char **p_n, int *fd);
char			*check_left(char **left, char **line, char **p_n);
char			*get_next_line(int fd);
char			*ft_strtrim_end(const char *s1);

#endif
