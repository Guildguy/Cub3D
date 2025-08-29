#ifndef LIBFT_H
# define LIBFT_H

/* Headers */
# include "cub3d.h"
# include "get_next_line.h"

// Libft/libft.c
bool	ft_isspace(int c);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *ptr, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char *s, char delim);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
