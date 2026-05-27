# Minishell

> A minimal Bash-like shell written in C (42 School project) featuring parsing, builtins, pipes, redirections, environment management, and signals.

![Language](https://img.shields.io/badge/language-C-blue)
![Project](https://img.shields.io/badge/42%20School-minishell-black)
![Topic](https://img.shields.io/badge/topic-shell%20%7C%20parsing%20%7C%20processes-informational)

## Overview

`Minishell` is a command-line interpreter designed to replicate core behaviors of `bash`. It focuses on understanding how a shell works internally:

- lexing + parsing user input into commands and arguments
- expanding environment variables
- executing builtins and external programs
- handling pipes (`|`) and redirections (`<`, `>`, `>>`, `<<`)
- managing processes (`fork`, `execve`, `waitpid`)
- handling interactive signals (`Ctrl-C`, `Ctrl-\`, `Ctrl-D`)

**Repository:** `otelliq/Minishell`  
**Default branch:** `main`

## Features

- **Builtins** (directory `minishell/builtins/`): commonly `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Pipelines**: `cmd1 | cmd2 | cmd3`
- **Redirections**:
  - input: `< file`
  - output: `> file`
  - append: `>> file`
  - heredoc: `<< LIMITER`
- **Environment handling** (`env.c`, `env_utils.c`)
- **Signal handling** (`signals.c`) for interactive behavior
- **Custom memory utilities** (e.g., `ft_malloc.*`) and custom `libft/`

## Screenshots

> No screenshots provided yet.

Suggested screenshots:
- prompt + a pipeline example
- heredoc usage
- `export` / env variable expansion example

## Installation & setup

### Prerequisites

- `make`
- C compiler (`cc` / `clang` / `gcc`)
- A UNIX-like OS (Linux/macOS)

### Build

From the repository root:

```bash
make -C minishell
```

This should produce the `minishell` executable (depending on Makefile rules).

## Usage

Run the shell:

```bash
./minishell/minishell
```

Example commands to try:

```bash
echo hello
export NAME=world
echo $NAME
ls -la | wc -l
cat < input.txt | grep foo > out.txt
```

## Project structure

```text
.
├── README.md
└── minishell/
    ├── Makefile
    ├── minishell.c
    ├── minishell.h
    ├── builtins/
    ├── lexer/
    ├── Parsing_system/
    ├── execve/
    ├── libft/
    ├── env*.c
    ├── fork.c
    ├── redirections*.c
    ├── signals.c
    ├── syntax_error.c
    └── utils*.c
```

## Notes

- If this project uses `readline`, make sure your environment links it properly (Linux/macOS differ).
- Behavior aims to match bash for the supported subset, but it is not a full POSIX shell.

## License

No license file is currently included in this repository.

If you want this to be reusable beyond the academic context, consider adding a `LICENSE` file (MIT/Apache-2.0 are common choices) and updating this section accordingly.
