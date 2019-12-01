/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sako <sako@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:24:29 by sako              #+#    #+#             */
/*   Updated: 2019/10/04 19:35:59 by sako             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

/*
**	macro functions
*/

# define IS_UPPER(x) ((x >= 'A' && x <= 'Z') ? 1 : 0)
# define IS_LOWER(x) ((x >= 'a' && x <= 'z') ? 1 : 0)
# define BUFF_SIZE 8
# define FD_SIZE 1024

/*
**	structures
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

long int			ft_atoi(const char *str);
void				ft_bzero(void *b, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(long long int nbr);
char				*ft_itoa_base_signed(long long int nbr, int base);
char				*ft_itoa_base_unsigned(uintmax_t nbr, int base);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memalloc_specific(int c, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_puterror(char *s, int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *str);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcmp_index(const char *s, char c);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free_end(const char *s1, char *s2);
char				*ft_strjoin_free_front(char *s1, const char *s2);
char				*ft_strjoin_new(char *s1, char *s2);
char				*ft_strjoin_new3(char *s1, char *s2, char *s3);
char				*ft_strjoin_new4(char *s1, char *s2, char *s3, char *s4);
size_t				ft_strlcat(char *dst,\
					const char *src, size_t dstsize);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1,\
					const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strrchr(const char*s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsub_end_new(char *s, unsigned int end, size_t len);
char				*ft_strsub_new(char *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					get_next_line(const int fd, char **line);

/*
**	some helpful functions
*/

int					count_words_in_str(char const *s, char c);
int					get_word_len(char const *s, char c);
int					check_signed_num_len(long long int n);
int					check_unsigned_num_len(uintmax_t n);
intmax_t			ft_floatlen(long double num, int flen);
char				*ft_ftoa(long double num, int flen);
int					ft_isfloot(char *str);
int					ft_isint(char *str);
int					ft_pow(int a, int b);
long double			ft_powf(long double a, int b);
void				ft_strtolower(char *str);
void				ft_strtoupper(char *str);
int					is_lower_letter(char c);
int					is_upper_letter(char c);
int					is_whitespace(char c);

#endif
