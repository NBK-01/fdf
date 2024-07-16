/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:32:10 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 10:00:34 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include "../includes/main.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_next(char *str);
char	*ft_append(int fd, char *rem, char *buffer);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_toupper(int c);
int		ft_putptr(unsigned long ptr);
int		ft_putptr_lowercase(unsigned int ptr);
int		ft_putptr_uppercase(unsigned int ptr);
int		ft_tolower(int c);
int		ft_printf(const char *str, ...);
int		ft_check(const char *str, va_list ap);
int		ft_print_hex(va_list ap);
int		ft_print_hex_lower(va_list ap);
int		ft_print_hex_upper(va_list ap);
int		ft_print_char(va_list ap);
int		ft_print_str(va_list ap);
int		ft_print_dig(va_list ap);
int		ft_print_unsigned(va_list ap);
int		ft_parse(const char *str, int i, va_list ap);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *src);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar(char c, int *count);
void	ft_bzero(void *str, size_t n );
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *dst, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_file	*ft_lstnew(char *content);
void	ft_lstadd_back(t_file **lst, t_file *new);
t_file	*ft_lstlast(t_file *lst);
void	ft_lstclear(t_file **lst, void (*del)(char*));
void	ft_lstdelone(t_file *lst, void (*del)(char*));

#endif
