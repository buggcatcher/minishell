/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/04 20:55:07 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen_v(char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(char *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = (char *)safe_alloc(n + 1, sizeof(char), "ft_strndup");
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(char *s)
{
	char	*c;
	size_t	i;

	i = ft_strlen_v(s);
	c = (char *)safe_alloc(i + 1, sizeof(char), "ft_strdup");
	if (c != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			c[i] = s[i];
			i++;
		}
		c[i] = '\0';
		return ((char *)c);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	int		i;
	int		j;

	i = ft_strlen_v(s1);
	j = ft_strlen_v(s2);
	final = (char *)safe_alloc(i + j + 1, sizeof(char), "ft_strjoin");
	if (!final)
		return (NULL);
	final[i + j] = '\0';
	while (j > 0)
	{
		j--;
		final[i + j] = s2[j];
	}
	while (i > 0)
	{
		i--;
		final[i] = s1[i];
	}
	return (final);
}

char	*ft_append_char(char *s, char c)
{
	int		len;
	char	*new;
	int		i;

	if (!s)
	{
		new = safe_alloc(2, sizeof(char), "ft_append_char_empty");
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	len = ft_strlen_v(s);
	new = (char *)safe_alloc(len + 2, sizeof(char), "ft_append_char");
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(s);
	return (new);
}

char *token_type_to_string(t_token_type type)
{
	switch (type)
	{
		case TK_WORD_0:         return "TK_WORD";
		case TK_PIPE_1:         return "TK_PIPE";
		case TK_REDIR_IN_2:     return "TK_REDIR_IN";
		case TK_REDIR_OUT_3:    return "TK_REDIR_OUT";
		case TK_REDIR_APPEND_4: return "TK_REDIR_APPEND";
		case TK_HEREDOC_5:      return "TK_HEREDOC";
		case TK_S_QUOTE_6:      return "TK_S_QUOTE";
		case TK_D_QUOTE_7:      return "TK_D_QUOTE";
		case TK_DOLLAR_8:       return "TK_DOLLAR";
		default:                return "UNKNOWN_TOKEN";
	}
}

char *fd_to_string(int fd)
{
	static char fd_str[32];
	
	switch (fd)
	{
		case -1:    return "CLOSED_FD";
		case 0:     return "STDIN";
		case 1:     return "STDOUT";
		case 2:     return "STDERR";
		default:
			snprintf(fd_str, sizeof(fd_str), "FD_%d", fd);
			return fd_str;
	}
}
