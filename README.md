*This project has been created as part of the 42 curriculum by ftessi.*

# ft_printf

A reimplementation of the C standard library function `printf()`, built as a
static library (`libftprintf.a`). This is a [42 School](https://42.fr) project.

The goal is to recreate a simplified version of `printf` from scratch — handling
a format string and a variable number of arguments — to understand how variadic
functions and output formatting work under the hood.

## What it does

`ft_printf` reads a format string, prints any normal characters as-is, and when
it hits a `%` followed by a conversion specifier it prints the matching argument
in the right format. It returns the total number of characters printed (or `-1`
if the format string is `NULL`).

```c
int ft_printf(const char *format, ...);
```

### Supported conversions

| Specifier | Prints                                                        |
|-----------|---------------------------------------------------------------|
| `%c`      | A single character                                            |
| `%s`      | A string                                                      |
| `%d`      | A signed decimal integer                                      |
| `%i`      | A signed decimal integer (same as `%d`)                       |
| `%u`      | An unsigned decimal integer                                   |
| `%x`      | An unsigned number in lowercase hexadecimal                   |
| `%X`      | An unsigned number in uppercase hexadecimal                   |
| `%p`      | A pointer address (in hexadecimal, prefixed with `0x`)        |
| `%%`      | A literal percent sign                                         |

## How it works

The library only uses two standard headers: `<stdarg.h>` (for variadic
arguments) and `<unistd.h>` (for `write`).

1. **`ft_printf`** loops over the format string one character at a time.
   - A normal character is written directly to standard output.
   - A `%` followed by another character triggers a conversion: the next
     character is the specifier, and it's passed to `ft_handle_conversion`.
2. **`ft_handle_conversion`** matches the specifier and pulls the matching
   argument off the `va_list` using `va_arg`, then calls the right helper.
3. Each helper writes its output and returns how many characters it printed, so
   `ft_printf` can keep a running total to return at the end.

The variadic mechanism is the core idea: `va_start` initializes the argument
list, `va_arg` fetches each argument with the type the specifier expects, and
`va_end` cleans up.

### Files

| File                   | Responsibility                                       |
|------------------------|------------------------------------------------------|
| `ft_printf.c`          | Main loop + conversion dispatcher                    |
| `ft_chrstr_helper.c`   | `%c` and `%s` (`ft_putchar`, `ft_putstr`)            |
| `ft_int_helper.c`      | `%d`, `%i`, `%u` (signed/unsigned integers)          |
| `ft_hexptr_helper.c`   | `%x`, `%X`, `%p` (hexadecimal and pointers)          |
| `ft_printf.h`          | Prototypes and includes                              |
| `Makefile`             | Builds the static library                            |

## Building

Run `make` to compile the static library `libftprintf.a`:

```sh
make        # build libftprintf.a
make clean  # remove object files
make fclean # remove object files and the library
make re     # rebuild from scratch
```

The library is compiled with `-Wall -Wextra -Werror`.

## Usage

Include the header in your source file and link against the library when
compiling.

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
    ft_printf("Printed %d characters.\n", len);
    ft_printf("A pointer: %p\n", &len);
    ft_printf("Hex: %x | Percent: %%\n", 255);
    return (0);
}
```

Compile and run it:

```sh
make
cc main.c -L. -lftprintf -o test
./test
```

Expected output:

```
Hello, world! You are 42 years old.
Printed 36 characters.
A pointer: 0x7ffeefbff5ac
Hex: ff | Percent: %
```

## Notes

- This is the **mandatory** part of the project (no flags/width/precision).
- `%d` and `%i` cast to `long` internally so that `INT_MIN` is handled safely.
- Returns `-1` when given a `NULL` format string.
