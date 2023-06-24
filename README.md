# 42-ft_printf

> Because putnbr and putstr aren’t enough

## Summary
This repository is a project for École 42. It is a replica for [printf](https://en.wikipedia.org/wiki/Printf) function. 

## Mandatory part

### General Information

| Program Name    | Turn in files | Makefile | External functs. | Libft authorized | Description |
| -------- | ------- | ------- | -------- | ------- | ------- |
| libftprintf.a  | *.c, */*.c, *.h, */*.h, Makefile | all, clean, fclean, re, bonus | malloc, free, write, va_start, va_arg, va_copy, va_end | yes | Write a library that contains ft_printf, a function that will mimic the real printf |

### Requirements

* The prototype of ft_printf should be int ft_printf(const char *, ...);
* You have to recode the libc’s printf function
* It must not do the buffer management like the real printf
* It will manage the following conversions: cspdiuxX%
* It will be compared with the real printf
* You must use the command ar to create your librairy, using the command libtool is forbidden.

## Compiling

1. Clone the repository. The repository depends [42-libft](https://github.com/hamza-cskn/42-libft) library. You have to clone too. So use `git clone --recursive git@github.com:hamza-cskn/42-libft.git`
2. Use `make all`command.
