/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 18:44:41 by aserrano          #+#    #+#             */
/*   Updated: 2019/12/16 18:46:18 by aserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct		s_toprint
{
	va_list			args;
	int				i;
	int				counter;
	const char		*format;
	int				width;
	int				precission;
	int				flags[4];
	int				precission_setted;
	int				mayus;
	int				memory;
	int				hex_i;
	int				percent;
	int				zerostr;
	int				ischar;
	int				unsig;
	int				precissioncpy;
	int				end;
	int				flagi;
	int				nullmemo;
	int				nullchar;
}					t_toprint;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define ZERO 0
# define MINUS 1
# define DOT 2
# define MULT 3

void				ft_putstr_fpf(char *s, t_toprint *toprint);
char				*memsw(t_toprint *toprint, char *num);
char				*width_bt_prec_mem(t_toprint *toprint, char *num);
void				last_num_mem(t_toprint *toprint, char *s, char *numf);
void				first_num_mem(t_toprint *toprint, char *s, char *numf);
void				print_mem(t_toprint *toprint);
void				first_str(t_toprint *toprint, char *s, char *str);
void				last_str(t_toprint *toprint, char *s, char *str);
char				*finalstr(t_toprint *toprint, char *str);
void				print_hex(t_toprint *toprint);
void				ft_reset_toprint(t_toprint *toprint);
char				*width_bt_prec(t_toprint *toprint, char *num);
char				*ft_unsigned_itoa(int n);
char				*ft_signed_itoa(int n);
char				*neg_prec_bt_width(t_toprint *toprint, char *num);
char				*pos_prec_bt_width(t_toprint *toprint, char *num);
void				ft_putstr(char *s, t_toprint *toprint);
void				manage_width_and_prec(t_toprint *toprint);
void				manage_flags(t_toprint *toprint);
void				print_char(t_toprint *toprint);
void				print_int(t_toprint *toprint);
void				ft_init(t_toprint *toprint, const char *format);
int					print_str(t_toprint *toprint);
void				read_arg(t_toprint *toprint);
int					ft_printf(const char *format, ...);
int					ft_strchr_gnl(const char *s, char c);
char				*ft_strjoin_and_free(char *str, char *buf);
int					get_next_line(int fd, char **line);
char				*ft_strdup_gnl(const char *src);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
long int			tenpow(int i);
int					n_size(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
int					ft_countwords(char const *s, char c);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void*));

#endif
