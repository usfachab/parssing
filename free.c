/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:33:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/03 22:33:13 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// while (var->data)
// 			{
// 				int i = 0;
// 				while (var->data->cmd_args && var->data->cmd_args[i])
// 				{
// 					free(var->data->cmd_args[i]);
// 					i++;
// 				}
// 				while (var->data && var->data->file)
// 				{
// 					free(var->data->file->file_name);
// 					var->data->file = var->data->file->next;
// 				}
// 				var->data = var->data->next;
// 			}
// 			free(var->command);
// 			free(var->file);
// 			free(var->_command);
// 			free(var->lexer);
// 			free(var->token);
// 			free(var->data);
// 			free(var);