#include "_env.h"

/**
 * 
 */
void	delete_node(t_env **list, t_env *node)
{
	t_env	*tmp;
	t_env	*next;

	if (!node || !*list)
		return ;
	tmp = *list;
	while (tmp && tmp->next != node)
		tmp = tmp->next;
	if (tmp && tmp->next && tmp->next == node)
	{
		next = tmp->next->next;
		free(tmp->next->key);
		free(tmp->next->value);
		free(tmp->next);
		tmp->next = next;
	}
}

/**
 * 
 */
void	append_node(t_env **list, t_env *node)
{
	t_env	*tmp;

	if (!node)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

/**
 * 
 */
t_env	*create_node(void)
{
	t_env	*node;

	node = (t_env *) ft_calloc(sizeof(t_env), 1);
	if (!node)
	{
		perror("failed to allocate 'struct s_env'");
		return (NULL);
	}
	node->key = NULL;
	node->value = NULL;
	node->next = NULL;
	return (node);
}
