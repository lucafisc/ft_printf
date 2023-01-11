<h1 align="center">ft_printf</h1>

<p align="center">
<img src="https://i.imgur.com/2SyDnUm.png" alt="drawing" width="120"/>
</p>

A static library that contains ft_printf, a function that mimics the original printf() function

- [Supported conversions](#supported-conversions)
- [How to use](#how-to-use)
- [How to test](#how-to-test)

## Supported conversions

| Specifier | Description | Examples |
| --- | --- | --- |
| `%c` | Prints any character from an ASCII table | `a` |
| `%s` | Prints an array of characters (string) | `Hello, world!` |
| `%i` and `%d` | Prints an integer in decimal notation | `-2147483648`|
| `%u` | Prints an unsigned integer in decimal notation | `2147483648` |
| `%x` | Prints an unsigned integer in hexadecimal notation (lowercase) | `8BeB0d3e` |
| `%X` | Prints an unsigned integer in hexadecimal notation (uppercase) | `8BEB0D3E` |
| `%p` | Prints the address of a pointer in hexadecimal notation | `0xfff000bd8` |
| `%%` | Prints the % sign | `%` |

## How to use

First clone this repository:

```
git clone git@github.com:lucafisc/ft_printf.git
```

Enter the directory:

```
cd ft_printf
```

Running `make` will compile the source code and create the library `ft_printf.a` :

```
make
```

This library can be used in any program written in `C`. Don't forget to include the header to your `.c` files:

```c
#include "./ft_printf.h"
```

To remove the object `.o` files run:

```
make clean
```

To also remove the library run:

```
make fclean
```

## How to test

Create a `main.c` file:

```c
// Include the header
#include "./ft_printf.h"

int	main(void)
{
	char str[] = "Hello, world!";
	char *ptr = str;
	// Call the function with any of the supported flags
	ft_printf("this is the string:\n%s \nand the address of the pointer:\n%p\n", str, ptr);
}
```

Compile the `main.c` file with the `ft_printf.a` library and execute the program:

```
cc -Wall -Werror -Wextra main.c ft_printf.a && ./a.out
```

The output in the terminal should be:

```
this is the string:
Hello, world! 
and the address of the pointer:
0x7ff7b85054ca // pointer address will differ
```
