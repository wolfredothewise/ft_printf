# ft_printf

> A custom implementation of the C standard library's `printf` function, written in C as part of the 42 curriculum.

[English](#english) · [Español](#español)

<a id="english"></a>

## English

### About

`ft_printf` recreates the core behavior of `printf` while respecting the constraints of the 42 project: no use of the original `printf`, a static library as output, and a clean, modular C implementation.

The project is focused on variadic functions, format-string parsing, recursive number conversion, hexadecimal formatting, pointer representation, and accurate return values.

### Supported conversions

| Conversion | Description |
| --- | --- |
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%p` | Prints a pointer in hexadecimal with a `0x` prefix |
| `%d` / `%i` | Prints a signed decimal integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints an unsigned hexadecimal integer in lowercase |
| `%X` | Prints an unsigned hexadecimal integer in uppercase |
| `%%` | Prints a literal percent sign |

`NULL` strings are represented as `(null)` and `NULL` pointers as `(nil)`, matching the expected project behavior.

### Build

Requirements:

- A C compiler such as `cc` or `clang`
- `make`
- A POSIX-compatible environment

Build the static library:

```bash
make
```

This creates `libftprintf.a`.

Clean object files or remove every generated file:

```bash
make clean
make fclean
make re
```

### Usage

Include the public header and link the generated archive:

```c
#include "libftprintf.h"

int main(void)
{
    ft_printf("User: %s | score: %d%%\n", "42", 100);
    return (0);
}
```

Compile it from the project root:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
./demo
```

### Project structure

| File | Responsibility |
| --- | --- |
| `ft_printf.c` | Main loop, variadic arguments, and conversion dispatch |
| `ft_handle_numbers.c` | Typed handlers for numeric and pointer conversions |
| `ft_putnbr.c` | Signed decimal output |
| `ft_putnbr_utils.c` | Unsigned, hexadecimal, and pointer output |
| `ft_putstr.c` | String output and `NULL` handling |
| `ft_putchar.c` | Character output |
| `libftprintf.h` | Public API |
| `Makefile` | Static-library build rules |

### Learning outcomes

- Working safely with `va_list` and variadic arguments
- Parsing format strings without relying on the standard `printf`
- Separating format dispatch from output helpers
- Handling signed, unsigned, hexadecimal, and pointer values
- Preserving the number of characters written as the function return value
- Building and linking a reusable static library

### Red-team application

Understanding format strings is useful in defensive red-team work. A custom `printf` implementation makes it easier to reason about how user-controlled format strings, type mismatches, unexpected `NULL` values, and output-length assumptions can affect a program. Those same concepts help when reviewing logging code, identifying unsafe formatting patterns, and building small C test harnesses for security assessments.

This project is educational: it does not exploit systems or replace a proper security review. Its value for red-team practice is learning to recognize the boundary between data and formatting instructions.

### Important note

This project was completed in **2025**. The 42 subject, toolchain, or evaluation environment may have changed since then, so this repository may not reflect the exact current version. It should nevertheless be **very close to the current project**, especially regarding its mandatory goals and supported conversions.

### License

This repository is intended for educational use within the 42 curriculum. Keep the original attribution and follow your school's rules when reusing the code.

<a id="español"></a>

## Español

### Sobre el proyecto

`ft_printf` recrea el comportamiento principal de `printf` respetando las restricciones del proyecto de 42: no utilizar el `printf` original, generar una biblioteca estática y mantener una implementación modular en C.

El proyecto trabaja con funciones variádicas, análisis de cadenas de formato, conversión recursiva de números, formato hexadecimal, representación de punteros y valores de retorno correctos.

### Conversiones implementadas

Implementa las conversiones obligatorias `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` y `%%`. Las cadenas `NULL` se muestran como `(null)` y los punteros `NULL` como `(nil)`.

### Compilación y uso

```bash
make
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
./demo
```

La biblioteca generada es `libftprintf.a`. Para limpiar los archivos compilados se pueden usar `make clean`, `make fclean` o `make re`.

### Aplicación en red team

Comprender las cadenas de formato resulta útil en red team defensivo: ayuda a analizar entradas controladas por usuarios, errores de tipos, valores `NULL`, logs inseguros y supuestos incorrectos sobre la longitud de salida. Este proyecto sirve como práctica para distinguir entre datos y directivas de formato y para crear pequeños harnesses de pruebas en C.

### Nota importante

Este proyecto se terminó en **2025**. El subject, las herramientas o el sistema de evaluación de 42 pueden haber cambiado, por lo que el repositorio quizá no coincida exactamente con la versión actual. Aun así, debería ser **prácticamente igual**, sobre todo en sus objetivos obligatorios y conversiones implementadas.
