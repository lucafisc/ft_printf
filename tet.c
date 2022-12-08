// C program for the above approach

#include <stdarg.h>
#include <stdio.h>

// Variadic function to add numbers
int	ft_printf(const char *n, ...)
{

}

// Driver Code
int main()
{
	printf("\n\n Variadic functions: \n");

	// Variable number of arguments
	printf("\n 1 + 2 = %d ",
		   AddNumbers(2, 1, 2));

	printf("\n 3 + 4 + 5 = %d ",
		   AddNumbers(3, 3, 4, 5));

	printf("\n 6 + 7 + 8 + 9 = %d ",
		   AddNumbers(4, 6, 7, 8, 9));

	printf("\n");

	return 0;
}
