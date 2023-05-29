/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:09:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/27 20:09:57 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
//#include "exec" 
typedef struct GLOBAL_STRUCT
{
	int exit_status;
	t_data	*data;
} t_global;