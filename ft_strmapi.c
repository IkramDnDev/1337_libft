/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idahhan <idahhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:31:45 by idahhan           #+#    #+#             */
/*   Updated: 2024/10/31 18:31:45 by idahhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char modify_char(unsigned int index, char c) {
    return c + index;
}*/

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int len;
    char *new_str;
    unsigned int i;

    len = 0;
    i = 0;
    if (!s || !f)
        return NULL;
    while (s[len])
        len++;
    new_str = (char *)malloc((len + 1) * sizeof(char));
    if (!new_str)
        return (NULL);
    while (i < len)
    {
        new_str[i] = f(i, s[i]);
        i++;
    }
    new_str[i] = '\0';

    return (new_str);   
}
/*
int main() {
    char *str = "hello";
    char *result = ft_strmapi(str, modify_char);
    if (result) {
        printf("%s\n", result); // Affiche "hfnos" en fonction de l'exemple
        free(result);
    }
    return 0;
}*/