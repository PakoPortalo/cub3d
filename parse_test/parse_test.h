/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fportalo <fportalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 11:24:44 by fportalo          #+#    #+#             */
/*   Updated: 2020/11/16 11:31:52 by fportalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TEST_H
# define PARSE_TEST_H
# include <stdio.h>

//para utilizar open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//para utilizar close
# include <unistd.h>

//po eso'
# include "gnl/get_next_line_bonus.h"

typedef struct mapdef {
	char	*res;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*floor;
	char	*ceil;
	char	*map;
} mapdef;


int			parse_test(char *file);

#endif
