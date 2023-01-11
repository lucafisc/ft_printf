# ft_printf

A static library that contains ft_printf, a function that mimics the original printf() function

## Supported conversions

| Specifier | Description | Examples |
| --- | --- | --- |
| `%c` | Prints any character from an ASCII table | `a` |
| `%s` | Prints an array of characters (string) | `Hello, world!` |
| `%i` and `%d` | Prints an integer in decimal notation | -2147483648 |
| `%u` | Prints an unsigned integer in decimal notation | `5000000000` |
| `%x` | Prints an unsigned integer in hexadecimal notation (lowercase) | `8BeB0d3e` |
| `%X` | Prints an unsigned integer in hexadecimal notation (uppercase) | `8BEB0D3E` |
| `%p` | Prints the address of a pointer in hexadecimal notation | `0xfff000bd8` |
| `%%` | Prints the % sign | `%` |

## How to use:

First clone this repository:

```css
git clone git@github.com:lucafisc/ft_printf.git
```

Enter the directory:

```css
cd ft_printf
```

Running `make` will compile the source code and create the library `ft_printf.a` :

```css
make
```

This library can be used in any program written in `C`. Don't forget to include the header to your `.c` files:

```css
#include "./ft_printf.h"
```

To remove the object `.o` files run:

```css
make clean
```

To also remove the library run:

```css
make fclean
```

## How to test it:

Create a `main.c` file:

```c
// Include the header
#include "./ft_printf.h"

int	main(void)
{
	char str[] = "Hello, world!";
	char *ptr = str;

	// Call the function with all the supported conversion flags
	ft_printf("> char: %c\n> string: %s\n> integer: %i\n
	> also an integer: %d\n> unsigned integer: %u\n
	> unsigned integer in hexadecimal notation (lowercase): %x\n
	> unsigned integer in hexadecimal notation (uppercase): %X\n
	> address of a pointer: %p\n> percentage sign: %%\n", 
	'a', str, -2147483648, 2147483647, 5000000000, 1234567890, 1234567890, ptr);
}
```

Compile the `main.c` file with the `ft_printf.a` library and execute the program:

```c
cc -Wall -Werror -Wextra main.c ft_printf.a && ./a.out
```

The output in the terminal should be:

```c
> char: a
> string: Hello, world!
> integer: -2147483648
> also an integer: 2147483647
> unsigned integer: 705032704
> unsigned integer in hexadecimal notation (lowercase): 499602d2
> unsigned integer in hexadecimal notation (uppercase): 499602D2
> address of a pointer: 0x7ff7bc5a94ca
> percentage sign: %
```
