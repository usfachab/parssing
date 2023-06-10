/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:49:03 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/08 02:37:51 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H

typedef struct GLOB_STRUCT
{
	t_data	*data;
	t_list	*env;
	char	*exit_status;
} t_glob;
#endif