/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:56:07 by malluin           #+#    #+#             */
/*   Updated: 2019/03/20 12:19:02 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE_GNL 64

typedef struct			s_blist {
	char				buff[BUFF_SIZE_GNL];
	int					ret;
	int					fd;
	struct s_blist		*next;
}						t_blist;

int						get_next_line(const int fd, char **line);
int						ft_del_return(char **str);
#endif
