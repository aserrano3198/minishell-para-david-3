[![License][license-logo]][license-url]

<br />
<p align="center">
  <h2 align="center">Minishell</h2>

  <p align="center">
    As beautiful as a shell
    <br />
    <a href="https://github.com/pabloocg/minishell/tree/master/srcs"><strong>Explore the docs »</strong></a>
 <br />
 
 
 
 <img src="record.gif" width="500" height="400" />
  </p>
</p>


<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

---

## About The Project

The objective of this project is create a simple shell. Yes, your own little bash or zsh. You will learn a lot about processes and file descriptors.

---

### Madatory Part

| Program name     	| minishell                                                                       	|
|------------------	|-------------------------------------------------------------------------------------	|
| Makefile         	| Yes                                                     	|
| External functs. 	| printf, malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno, getenv                              	|
| Libft authorized 	| Yes                                                                                 	|
| Description      	| Write a shell	|

---

It must implement the builtins like in bash:

- **echo** with option ’-n’
- **cd** with only a relative or absolute path
- **pwd** without any options
- **export** without any options
- **unset** without any options
- **env** without any options and any arguments
- **exit** without any options

`;` in the command should separate commands like in bash.

`’` and `"` should work like in bash except for multiline commands.

Redirections `<` `>` `>>` should work like in bash except for file descriptor aggregation.

Pipes `|` should work like in bash except for multiline commands.

Environment variables ($followed by characters) should work like in bash.

`$?` should work like in bash.

`ctrl-C`, `ctrl-D` and `ctrl-\` should have the same result as in bash.

## Getting Started

### Installation

1. Clone the repository
    ```sh
    git clone https://github.com/pabloocg/minishell.git
    ```
2. Enter the repository and run make
    ```sh
    cd minishell && make
    ```

## Usage
```
./minishell
```

## License

Distributed under the GNU GPLv3. See `LICENSE` for more information.

## Contact

Pablo Cuadrado García </br>
[Linkedin][linkedin-url] - pablocuadrado97@gmail.com

[license-logo]: https://img.shields.io/cran/l/devtools?style=for-the-badge
[license-url]: https://github.com/pabloocg/minishell/LICENSE
[linkedin-url]: https://linkedin.com/in/pablo-cuadrado97

