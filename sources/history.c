/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:45:39 by grcharle          #+#    #+#             */
/*   Updated: 2026/02/23 14:45:41 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	print_history(t_history *list)
//{
//	(void) list;
//	// while (list)
//	// {
//	// 	// printf("%i : %s\n", list->nb_command, list->command);
//	// 	list = list->next;
//	// }
//}

//void	clear_history(t_history **list)
//{
//	(void) list;
//	// //vider la liste chainee et la free
//	// t_history *temp;
	
//	// if(!*list)
//	// 	return ;
//	// while (*list)
//	// {
//	// 	temp = (*list)->next;
//	// 	if (temp->command)	
//	// 		free(temp->command);
//	// 	free (*list);	
//	// 	(*list) = temp;
//	// }
//}

//void	update_history(char *command)
//{
//	(void) command;
//	// t_history	*node;
//	// t_history 	*temp;
	
//	// if(!command)
//	// 	return (-1);
//	// node = (t_history *)malloc(sizeof(t_history));
//	// if (!node)
//	// 	return (-1);
//	// node->command = (char *)malloc(sizeof(char) * ft_strlen(command) + 1);
//	// if (!node->command)	
//	// {
//	// 	free(node);
//	// 	return (-1);
//	// }
//	// (void) ft_strlcpy(node->command, command, ft_strlen(command));
//	// node->next = (struct s_history *) NULL;
//	// temp = *list;
//	// while (temp->next)
//	// 	temp = temp->next;
//	// temp->next = node;
//	// return (0);
//}
