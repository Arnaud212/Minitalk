/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:10:42 by agiraud           #+#    #+#             */
/*   Updated: 2021/09/28 11:26:19 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_flags
{
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
}				t_flags;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char				*ft_strtrim(char const *s1, char const *set);
int					ft_printf(const char *format, ...);
int					ft_putchar(int c);
int					ft_parse(const char *str, va_list args);
int					ft_parse_flags(const char *str, int i,
						t_flags *flags, va_list args);
t_flags				ft_init_struct(void);
int					ft_is_type(int c);
int					ft_is_flag(int c);
int					ft_parse_type(int c, t_flags flags, va_list args);
int					ft_flags_dot(const char *str, int i, t_flags *flags,
						va_list args);
t_flags				ft_flags_minus(t_flags flags);
t_flags				ft_flags_width(va_list args, t_flags flags);
t_flags				ft_flags_digit(char c, t_flags flags);
int					ft_print_c(char c, t_flags flags);
int					ft_handle_width(int width, int minimum, int put_zero);
int					ft_putstr_prec(char *str, int prec);
int					ft_print_s(char *str, t_flags flags);
char				*ft_itoa_base(unsigned long long value, int base);
int					ft_print_p(unsigned long long p, t_flags flags);
char				*ft_str_tolower(char *str);
char				*ft_u_itoa(unsigned int n);
int					ft_print_u(unsigned int nb, t_flags flags);
int					ft_print_d_i(int nbr, t_flags flags);
int					ft_print_hexa(unsigned int nb, int upper, t_flags flags);
int					ft_print_percent(t_flags flags);

#endif
