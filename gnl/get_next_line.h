/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:24:03 by dadeyemi          #+#    #+#             */
/*   Updated: 2024/02/15 13:37:58 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
    char *buf;
    char *tmp;
    char *mrr;
    int count;
    int i;
    size_t len;
} t_list;


size_t	ft_strlen(const char *s);
char	*ft_substr(const char  *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char    *get_next_line(int fd);
char	*ft_substr_free( char *s, unsigned int start, size_t len);
char    *ft_resize(char *str, size_t start, int len);


#endif

