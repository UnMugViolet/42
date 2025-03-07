/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionnary.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:33:57 by pjaguin           #+#    #+#             */
/*   Updated: 2025/03/07 17:31:28 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONNARY_H
# define DICTIONNARY_H

/*---------------------------- COLORS ---------------------------------*/

# define CYN "\x1B[36m"
# define BLK "\x1B[0m"

/*--------------------------- OPERATORS --------------------------------*/

# define NEWLINE				0
# define PIPE 					1
# define DOUBLE_PIPE			2
# define AMPERSAND				3
# define DOUBLE_AMPERSAND		4
# define LEFT_BRACKET			5
# define DOUBLE_LEFT_BRACKET	6
# define RIGHT_BRACKET			7
# define DOUBLE_RIGHT_BRACKET	8

/*----------------------------- TOKEN ----------------------------------*/

#define TOKENS (const char *[]) { "<", ">", "<<", ">>", "|", "||", "&&", "$", NULL }

/*--------------------------- DEFAULT --------------------------------*/

# define DEF_PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"


#endif
