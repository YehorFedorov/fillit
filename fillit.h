/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:10:22 by efedorov          #+#    #+#             */
/*   Updated: 2017/01/19 10:34:55 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_block
{
	char			s;
	char			*src;
	int				x[4];
	int				y[4];
	struct s_block	*next;
}				t_block;

char			*ft_readfile(char *file);
t_block			*ft_str(char *tmp);
int				ft_validate(int fd);
int				ft_check(const char *str);
char			*ft_strtrim(char const *s);
char			*ft_strrev(char *str);
char			*ft_strnew(size_t size);
char			*ft_strncpy(char *dest, const char *src, size_t i);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *s1);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strndup(const char *s1, size_t n);
t_block			*ft_basic_coords(t_block *fig);
void			ft_fig_coords(t_block *fig, char **s);
void			ft_new_coords(t_block *fig, int x, int y);
int				ft_max(int numb);
void			ft_error(void);
char			**ft_max_str(char **str, int max);
char			**ft_final(t_block *fig, int max);
char			**ft_strsplit(char const *s, char c);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
void			ft_putchar(char c);

#endif
