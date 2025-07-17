/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:47:01 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/17 16:47:01 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

/* Signal handling functions */
void	handle_sigint(int sig);
void	setup_signals(void);
void	disable_signals(void);
void	ignore_signals(void);

#endif
