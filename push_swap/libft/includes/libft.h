/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:07:27 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/14 17:04:53 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_is_whitespace(int c);

int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_str_tolower(char *str);
char				*ft_str_toupper(char *str);
size_t				ft_strlen(const char *str);
size_t				ft_nbr_len(unsigned long nbr);
void				ft_bzero(void *str, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *str, const char *to_find,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char c);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
size_t				ft_count_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
size_t				ft_count_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_reverse(char *str);

#endif
