/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:21:51 by fjewfish          #+#    #+#             */
/*   Updated: 2020/08/29 09:27:32 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int					get_next_line(char **line);
int					if_nnn(char *str);

size_t				ft_strlen(const char *s);

char				*join_str(const char *s1, const char *s2);

#endif
