*This project has been created as partof the 42 curriculum by <asuarez>*

#Description
This project imitates the std output behaviour of printf 
The goal was to get hands on variadic functions and how to navidate hem


Printf is a function with a variable amount of args
To use this C ofers a library with vz
Va_start opens the arguments giving acces to va_list an argumnet list 
Va_end closes it 
Print fucntion takes the string that is the first element of the lsit 
Now we want to relate the first argument with the subsequents
Each match of the %* relates to the following string 
By looping subsequents args and runniong functiosn such as itoa , and such we convert each type to string 
Once the conversion is made we bring the full string by string concating 
the string that we have recured and the added part keeping the roll.
Investigation Ia
Developing

1. va_start

    What it does: Initializes the va_list variable so it points to the first optional argument.

    How it's used: va_start(args, last_named_param);

    Why: It "opens" the argument list, using the last fixed parameter in your function signature as a starting anchor.

2. va_arg

    What it does: Retrieves the current argument and automatically shifts the internal pointer forward to the next one.

    How it's used: type val = va_arg(args, type);

    Why: Since C doesn't know what type is coming next, you must explicitly tell it the expected data type (e.g., int, char *).

3. va_copy

    What it does: Makes an exact copy of an existing va_list.

    How it's used: va_copy(dest_args, src_args);

    Why: Useful if you need to scan/read through the exact same set of arguments more than once without losing your place in the original list. (Must be cleaned up with its own va_end later).

4. va_end

    What it does: Cleans up and closes the va_list.

    How it's used: va_end(args);

    Why: Prevents undefined behavior or memory leaks before your function exits. Every va_start (and va_copy) needs a matching va_end.
#Instructions


#Resources
https://www.geeksforgeeks.org/c/variadic-functions-in-c/
IA set on a q&a for variadic questiosn
Brainstorming with peers 

#Detailed Description
printf can have a variable amount of argumnets
To solve that isue we use variadic fucntion
f(const char*str,...) tye function
this opens a variable type va_list 
va list initializes with va_start
this opens the unknown amount of arguments to be called in succesion from the ... section
va_ends to close the recursion.
now that the va_list gives us acces to all the argumnets
we just need to read the first arguments of f() the const string 
and checking when we find the % 
each time a % is foud we call a conversion fucntion that redirects to its ascii conversion
the conversion returns the amount of characters converted and so we can keep count of the total characters that we how in stdoutput


for testing ::
add a main.c on the root of the repository such has 
#include "ft_printf.h"


#include <stdio.h>
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"


int	main(void)
{
	printf("\n--- CHAR ---\n");
	printf("printf:    ");
	ft_printf("ft_printf: ");
	printf("\nprintf:    ");
	printf("%c\n", 'A');
	ft_printf("ft_printf: %c\n", 'A');

	printf("\n--- STRINGS ---\n");
	printf("printf:    %s\n", "");
	ft_printf("ft_printf: %s\n", "");
	printf("printf:    %s\n", (char *)NULL);
	ft_printf("ft_printf: %s\n", (char *)NULL);

	printf("\n--- INTEGERS ---\n");
	printf("printf:    %d\n", INT_MIN);
	ft_printf("ft_printf: %d\n", INT_MIN);
	printf("printf:    %d\n", INT_MAX);
	ft_printf("ft_printf: %d\n", INT_MAX);
	printf("printf:    %d\n", 0);
	ft_printf("ft_printf: %d\n", 0);
	printf("printf:    %i\n", -42);
	ft_printf("ft_printf: %i\n", -42);

	printf("\n--- UNSIGNED ---\n");
	printf("printf:    %u\n", UINT_MAX);
	ft_printf("ft_printf: %u\n", UINT_MAX);
	printf("printf:    %u\n", 0);
	ft_printf("ft_printf: %u\n", 0);

	printf("\n--- HEX ---\n");
	printf("printf:    %x\n", UINT_MAX);
	ft_printf("ft_printf: %x\n", UINT_MAX);
	printf("printf:    %X\n", 0);
	ft_printf("ft_printf: %X\n", 0);

	printf("\n--- POINTER ---\n");
	printf("printf:    %p\n", (void *)NULL);
	ft_printf("ft_printf: %p\n", (void *)NULL);

	printf("\n--- PERCENT ---\n");
	printf("printf:    %%\n");
	ft_printf("ft_printf: %%\n");

	printf("\n--- MIXED ---\n");
	printf("printf:    %d %s %c %x %%\n", 42, "test", 'A', 255);
	ft_printf("ft_printf: %d %s %c %x %%\n", 42, "test", 'A', 255);

	return (0);
}


& run
make 
cc main.c ./printlibft.a -o executablefillername
