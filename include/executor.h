#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "builtins.h"
# include "minishell.h"

/* ========================================================================== */
/*                            MAIN EXECUTOR                                   */
/* ========================================================================== */

int		ft_executor(t_ms_data *ms_data);

/* ========================================================================== */
/*                         COMMAND EXECUTION                                  */
/* ========================================================================== */

int		execute_single_command(t_ms_data *ms_data, t_cmd *cmd);
int		execute_external_single(t_ms_data *ms_data, t_cmd *cmd);
int		execute_pipeline(t_ms_data *ms_data, t_cmd *cmd_list);

/* ========================================================================== */
/*                         BUILTIN HANDLING                                   */
/* ========================================================================== */

int		ft_is_builtin(char *cmd);
int		execute_builtin(t_ms_data *ms_data, char **argv);

/* ========================================================================== */
/*                         REDIRECTION HANDLING                               */
/* ========================================================================== */

int		apply_redirections(t_redir *redir_list);

/* ========================================================================== */
/*                         PATH & ENVIRONMENT                                 */
/* ========================================================================== */

char	*find_command_path(char *command, t_envp *env);
char	**envp_to_array(t_envp *env);
void	free_array(char **array);

/* ========================================================================== */
/*                         SIGNAL HANDLING                                    */
/* ========================================================================== */

void	setup_child_signals(void);

#endif
