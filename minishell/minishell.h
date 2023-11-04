/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliq <otelliq@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:26:50 by mboudrio          #+#    #+#             */
/*   Updated: 2023/09/30 21:58:38 by otelliq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include "ft_malloc.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	char			*command;
	char			**args;
	char			**all;
	char			*linee;
	char			**cmdarg;
	struct s_list	*next;

}					t_list;

typedef struct s_env
{
	t_list			*head;
	t_list			*tail;
	int				size;

}					t_env;

typedef struct s_elem
{
	char			*content;
	char			*name;
	char			*value;
	struct s_elem	*next;

}					t_elem;

typedef struct s_sum
{
	t_elem			*exp;
	t_elem			*env;
	int				exitt;
}					t_sum;

typedef struct s_data
{
	int				sq;
	int				dq;
	int				pid;
	char			**env;
	t_list			*lex;
	char			**envrt;
	int				input;
	int				output;
	int				herdok;
	char			*here_doc;
	int				here_doc_flag;
	char			**p;
	int				count_var;
	char			*var;
	t_sum			*sum;
	int				i;
	int				single_quote;
	int				double_quote;
	int				ij;
	int				jk;
	char			*result;
}					t_data;

typedef struct s_slp_p
{
	int				i_c;
	int				word_count;
	int				inside_quotes;
	int				w_s;
	int				i;
}					t_slp_p;

int					reading_line(char *line);
void				lunch_program_logic(char **env);
void				setting_global_data(char **env);
void				initialize_data(t_data **data);
void				initialize_sum(t_sum **sum, char **env);
void				execute_builtin(t_list *list, t_sum *s);
void				initialize_Data(char **env);
void				execute_program_logic(t_data *data, t_sum *sum);
void				initialize_data_and_sum(t_data **data, t_sum **sum,
						char **env);

/*---------------------------------------------------------------------*/
// UTILS FUNCTIONS :
/*---------------------------------------------------------------------*/
int					ft_isspace(char c);
int					is_space(char c);
int					is_equal(char *s);
int					is_builtin(t_list *list);
int					only_spaces(char *str);
char				*ft_strndup(char *s1, int n);
char				*add_spaces(char *input);
int					special_char(char c);
char				*ft_strncpy(char *s1, const char *s2, int n);
char				*ft_strcpy(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
char				*return_without_quote(char *str);
char				*fill_the_quotes(char *str, char curr_char, char curr,
						int res);

/*---------------------------------------------------------------------*/
// SYNTAX ERRORS FUNCTIONS :
/*---------------------------------------------------------------------*/

int					pipes_errors(char *line);
int					matched(const char *str);
int					checking_errors(char *str);
int					pipe_location(char *str);
int					has_mismatched_quotes(const char *str);
int					process_double_quotes(const char *str);
int					process_single_quotes(const char *str);
int					redirection_syntax_error(char *line);
// int					redirection_syntax_core( int i, char *line);

/*---------------------------------------------------------------------*/
// EXPANSION FUNCTIONS :
/*---------------------------------------------------------------------*/

int					countvar(char *res);
char				*get_env(t_data *data, int i);
void				one_command(t_list *list, t_data *data, t_sum *sum);
void				check_mult_command(t_list *list, t_data *data, t_sum *sum);
void				pre_tokenization(char *line, t_data *data, t_sum *sum,
						t_elem *env);

/*---------------------------------------------------------------------*/
// LEXER FUNCTIONS :
/*---------------------------------------------------------------------*/

t_list				*initialize_list(char **p);
t_list				*create_new_element(char *line);
t_list				*last_node1(t_list *list);
// void				//free_list(t_list *list);
void				add_last_node(t_list **lst, t_list *n);
int					empty_list(t_list *list);
char				**fill_args(char **p);
char				*expansion(char *cmd, t_data *data, t_sum *sum,
						t_elem *env);
char				*expd(char *exp, t_data *data, t_elem *env, t_sum *sum);
char				*apply_expansion(t_data *data, char *exp, t_elem *env,
						t_sum *sum);
void				apply_core(char *exp, t_data *data, t_elem *env,
						t_sum *sum);
char				**fill_args1(char **p);
char				**fill_args2(char **p);
char				**fill_args2(char **p);
t_list				*create_command_list(char *line);
void				execute_commands(t_list *command, t_data *data, t_sum *sum);
int					list_length(t_list *head);

/*---------------------------------------------------------------------*/
// ENV FUNCTIONS :
/*---------------------------------------------------------------------*/

t_elem				*create_node(char *s);
t_elem				*last_node(t_elem *list);
t_elem				*env_init(char **env);
void				addback_node(t_elem **lst, t_elem *n);
char				*env_first(char *s);
char				*env_last(char *s);
void				env_printer(t_sum *s);
char				**change_list_to_array(t_elem *env);

/*---------------------------------------------------------------------*/
// REDIRECTIONS FUNCTIONS :
/*---------------------------------------------------------------------*/

int					finding_here_doc(t_list *s);
int					finding_rederection(t_list *s);
void				applying_her_doc(t_data *data, t_list *s);
void				applying_redirections_and_fd(t_data *data, t_list *s);
void				here_doc_redirection(t_data *data, t_list *s, int i);
void				output_redirection(t_data *data, t_list *s, int i);
void				append_redirection(t_data *data, t_list *s, int i);
void				input_redirection(t_data *data, t_list *s, int i);

/*---------------------------------------------------------------------*/
// BUILTINS FUNCTIONS :
/*---------------------------------------------------------------------*/

void				echo_command(t_list *list);
void				pwd_command(void);
void				cd_command(t_list *com, t_sum *zone);
void				export_command(t_list *list, t_sum *g);
void				exit_command(t_list *list, t_sum *sum);

/*---------------------------------------------------------------------*/
// CD FUNCTIONS :
/*---------------------------------------------------------------------*/

void				change_to_home(t_elem *head);
void				change_old_directory(t_elem *head);
t_elem				*search_node(t_elem *head, char *word);
void				change_directory(t_elem *head);

/*---------------------------------------------------------------------*/
// EXPORT FUNCTIONS :
/*---------------------------------------------------------------------*/

int					value_checker(t_elem *elements, char *s);
void				export_new_variables(t_list *list, int i, t_sum *g,
						t_elem *exp);
int					is_valid_export_variable(char *variable_name);

/*---------------------------------------------------------------------*/
// EXECVE FUNCTIONS :
/*---------------------------------------------------------------------*/

void				ft_execve(t_list *list, t_sum *sum, char **elementv, int i);
void				unset_command(t_list *list, t_sum *sum);
void				ft_fork(t_list *list, t_sum *sum, t_data *data);
void				ft_child(t_list *list, int *fid, t_data *data, t_sum *sum);
void				ft_signals(int sig);
void				rl_replace_line(const char *text, int clear_undo);
int					finding_rederection(t_list *s);
void				execute_exe(t_list *list, t_sum *sum);

/*---------------------------------------------------------------------*/
// PIPE_HELPER FUNCTIONS :
/*---------------------------------------------------------------------*/

t_slp_p				*init_slp_p(void);
void				fill_it(t_slp_p *val, char *word, char *input,
						char **words);
char				**splitstring(char *input);

/*---------------------------------------------------------------------*/
// EXECVE FUNCTIONS :
/*---------------------------------------------------------------------*/

char				*ft_strjoin_env(char *s1, char *s2);
char				**find_executable(char *command, t_elem *elem);
void				access_handling(char *s, char **ss, char **envv);
int					ft_access(char *path, int res);
int					path_finder(t_elem *element);
char				*ft_strjoin_env(char *s1, char *s2);
void				add_space_norm(char *input, int len, char currentchar,
						t_data *data);
int					is_empty(const char *line);
int					check_digit(char *str);
void				fill_them(t_slp_p *val, char *word, char *input,
						char **words);
char				*fill_the_red(int len, int i, int j, char *input);
void				free_t_elem(t_elem *elem);
void				free_sum(t_sum *sum);
void				node_compare(t_elem *env, t_elem *exp);
void				freeing(char *value, char *name);

#endif
