/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:47:01 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/17 16:47:01 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "types.h"

/* Main execution functions */
int		executor_loop(t_node *node, t_shell_state *state);
int		exec_in_parent(t_node *node, t_shell_state *state);
void	update_fds_for_next_cmd(t_node *node, int pipe_fd[2], int *prev_fd);
int		wait_for_last(pid_t last_pid, int *exit_status);

/* Builtin detection and execution */
int		is_parent_builtin(char *cmd);
int		is_child_builtin(char *cmd);
int		should_execute_in_parent(t_node *node);
int		is_builtin(char *cmd);
char	*join_key_value(char *key, char *value);
int		spawn_forked_command(t_node *n, int pipe_fd[2], int prev_fd, t_env *e);
int		exec_builtin(char **args, t_env **env);
int		handle_builtin_if_applicable(t_node *n, t_env **e, int *last_status);
int		create_pipe_if_needed(t_node *node, int pipe_fd[2]);

/* Redirection handling */
int		apply_redirects(t_redir *redirs);
int		ft_handle_out_append(t_node *node);
int		ft_handle_in(t_node *node);

/* Path resolution */
char	*resolve_path(char *cmd, t_env *env, t_node *node, t_node *head);

/* Child process execution */
void	exec_child(t_node *node, int pipe_out[2], int pipe_in, t_env *env, t_node *head);

/* File descriptor management */
int		switch_fd(int src, int dest);
int		save_fd(int fd);
int		save_stdout(void);
int		open_outfile(char *filename);

#endif
