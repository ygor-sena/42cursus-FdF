/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yde-goes <yde-goes@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:45:03 by yde-goes          #+#    #+#             */
/*   Updated: 2022/07/07 22:44:03 by yde-goes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*temp_node;

	if (!lst || !del)
		return ;
	temp_lst = *lst;
	while (temp_lst != NULL)
	{
		temp_node = temp_lst->next;
		ft_lstdelone(temp_lst, del);
		temp_lst = temp_node;
	}
	*lst = NULL;
}
