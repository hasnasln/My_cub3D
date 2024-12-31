/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:38:09 by haslan            #+#    #+#             */
/*   Updated: 2023/10/22 15:21:28 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int					ft_atoi(const char *str);

void				ft_bzero(void *ptr, size_t n);

void				*ft_calloc(size_t coun, size_t size);

int					ft_isalnum(int c);

int					ft_isalpha(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int k);

char				*ft_itoa(int n);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dest, const void *src, size_t n);

void				*ft_memmove(void *dest, const void *str, size_t n);

void				*ft_memset(void *ptr, int value, size_t num);

char				**ft_split(char const *s, char c);

char				*ft_strchr(const char *str, int c);

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlcat(char *dest, const char *src, size_t size);

size_t				ft_strlcpy(char *dest, const char *src, size_t size);

size_t				ft_strlen(const char *str);

int					ft_strncmp(const char *str1, const char *str2, size_t n);

char				*ft_strnstr(const char *dest, const char *src, size_t n);

char				*ft_strrchr(const char *str, int c);

char				*ft_strtrim(char const *s1, char const *set);

char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_tolower(int c);

int					ft_toupper(int a);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char *s, int fd);

void				ft_putendl_fd(char *s, int fd);

void				ft_putnbr_fd(int nunmber, int fd);

char				*ft_strdup(const char *s1);

#endif