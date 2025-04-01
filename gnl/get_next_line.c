/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadeyemi <dadeyemi@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:56 by dadeyemi          #+#    #+#             */
/*   Updated: 2025/04/01 10:42:19 by dadeyemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_resize(char *str, size_t start, int len)
{
    t_list var;
    
    var.tmp = NULL;
    var.tmp = ft_substr(str, start, len);
    free(str);
    str = ft_substr(var.tmp, 0, ft_strlen(var.tmp));
    free(var.tmp);
    return (str);
}

static char *ft_cut_line(char *str)
{
    t_list var;
    
    var.i = 0;
    while (str[var.i] != '\n' && str[var.i] != '\0')
        var.i++;
    if (ft_strchr(str, '\n'))
        var.i++;
    var.tmp = ft_substr(str, 0, var.i);        
    if (var.tmp == NULL || str == NULL || str[0] == '\0' || var.tmp[0] == '\0')
    {
        free (var.tmp);
        str = NULL;
        return (NULL);
    }
    return (var.tmp);
}

static char *ft_join_read(char *str, int fd)
{
    t_list var;
    
    var.count = 1;
    var.buf = NULL;
    while (var.count > 0 && !(ft_strchr(var.buf, '\n')))
    {
        var.i = 0;
        if (var.buf != NULL)
            free(var.buf);
        var.buf = (char *)malloc(1 * (BUFFER_SIZE + 1));
        if (var.buf == NULL)
            return (NULL);
        while (var.i < BUFFER_SIZE + 1)
            var.buf[var.i++] = '\0';
        var.count = read(fd, var.buf, BUFFER_SIZE);
        if (var.count < 0)
            return (NULL);
        var.buf[var.count] = '\0';
        if (var.count < BUFFER_SIZE && var.count > 0)
            var.buf = ft_resize(var.buf, 0, var.count);
        str = ft_strjoin(str, var.buf);
    }
    free(var.buf);
    return (str);
}


char *get_next_line(int fd)
{   
    t_list var;
    static char *letto[1024];
     
    var.i = 0;
    var.tmp = NULL;
    if (fd < 0)
        return (NULL);
    if (letto[fd] == NULL)
    {
        letto[fd] = malloc(sizeof(letto[fd]) * (BUFFER_SIZE + 1));
        if (letto[fd] == NULL)
            return (NULL);
        while (var.i < BUFFER_SIZE + 1)
            letto[fd][var.i++] = '\0';
    }
    if (!(ft_strchr(letto[fd], '\n')))
        letto[fd] = ft_join_read(letto[fd], fd);
    if (!(var.tmp = ft_cut_line(letto[fd])))
        return (NULL);
    if (!var.tmp || var.tmp == NULL)
            return (NULL);
        letto[fd] = ft_resize(letto[fd], ft_strlen(var.tmp), ft_strlen(letto[fd]) - ft_strlen(var.tmp));
    if (ft_strlen(var.tmp) == BUFFER_SIZE || letto[fd] == NULL)
    {
        free(letto[fd]);
        letto[fd] = NULL;
    }
    if (var.tmp != NULL && var.tmp[0] != '\0')
        return (var.tmp);
    else
    {
        free(var.tmp);
        return NULL;
    }
}

int main()
{
    t_list var;
    
    var.i = 0;
    int fda = 0;
    fda = open("./testo.txt", O_RDONLY);

    while (var.i++ < 8)
        printf("%s", get_next_line(fda));
    return 0;
}
