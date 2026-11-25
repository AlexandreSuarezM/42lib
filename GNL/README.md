*This project has been created as part of the 42 curriculum by asuarez*

# Description
call get line of a file descriptor to get the first line
on the bonus part multiple fd are handled
subsequent calls in the same main provide subsequent lines.
A document can end with no \n
Failures at each point have to free the memory allocartions.

# Instructions
git clone  the repo 
cd          in the repo 

Supose you want to test a main.c 
Compile the whole .o in one file test : 
Feel free to set the BUFFER SIZE:

**cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c -o test**

then run  ./test

git clone  the repo 
cd          in the repo 

compile with 
make the .o files with  
cc -Wall -Wextra -Werror -D BUFFER_SIZE=BUFFER_SIZE -c  *.c -o *.o 
for * 
get_next_line.c & get_next_line_utils.c    idem for bonuses
BUFFER_SIZE defaults to 42  
then the main with 
cc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -g main.c *.o -o   *
this generates the out



# Details.
IA depured : 
1. Project Overview

The goal of Get Next Line (GNL) is to write a function that reads from a file descriptor and returns one line at a time.

A line consists of all characters read up to and including the first \n, if one exists. If the end of the file is reached and there are still characters left, the function returns the remaining characters as the last line, even if it does not end with \n.

If there is nothing left to read, or an error occurs, the function returns NULL.

The function must preserve any data that has been read but not yet returned, so that subsequent calls can continue where the previous call stopped.
2. The Main Problem
Why not read one character at a time?

One possible approach would be to read a single character on every call to read() until a newline is found.

However, this would require many calls to read(), especially when working with large files. It could also become inefficient if we allocated memory repeatedly for every character.

Instead, we read a chunk of data into a buffer whose size is defined by BUFFER_SIZE.

This introduces a new problem: the buffer may contain more than one line, or part of the next line.
The buffer problem

Imagine that the file contains:
text

Hello
My name is John
I am learning C

If BUFFER_SIZE is large enough, a single call to read() might read:
text

Hello\nMy name is John\nI am learning C

We only want to return the first line:
text

Hello\n

However, the remaining data has already been read from the file descriptor.

If we discard the buffer after returning the first line, we lose the data belonging to the following lines.

We therefore need a way to preserve the data that has been read but has not yet been returned.
3. The Solution: A Static Variable

To solve this problem, we use a static variable to preserve the remaining data between calls to get_next_line().

For the mandatory part, we can use:
c

static char *stack;

A static variable retains its value after a function finishes executing. Unlike a local variable, it is not recreated from scratch on every call.

The stack stores all the characters accumulated from previous reads that have not yet been returned as a line.

The general process is:

    Check whether stack already contains a complete line.
    If it does, extract and return that line.
    If it does not, read more data into buffer.
    Append the new data to stack.
    Repeat until a newline is found or the end of the file is reached.
    Return the next line while preserving any remaining characters.

Because stack is static, the remaining data is available when get_next_line() is called again.

Important: A static pointer is initialized to NULL by default. However, freeing the memory it points to does not reset the pointer automatically. After freeing it, we must set it to NULL to avoid leaving a dangling pointer.
4. Understanding the Variables
buffer
c

char buffer[BUFFER_SIZE + 1];

buffer temporarily stores the data read by read().

The extra character allows us to append a terminating \0 when needed, provided that we explicitly add it.

The actual number of bytes read is determined by the return value of read().
buffer_len

buffer_len stores the number of bytes successfully read by read().

We use it to know exactly how many characters from buffer should be appended to stack.

This is important because read() does not necessarily fill the entire buffer. It may return fewer bytes than BUFFER_SIZE.

It also prevents us from treating unused parts of the buffer as valid data.
stack

stack stores the accumulated data from successive reads.

It grows whenever more data is needed to complete the next line. Once a line is extracted, any characters after the newline must remain available for the next call.
line

line contains the line that will be returned by get_next_line().

It includes all characters up to and including the first \n, if present.

The returned line must be allocated dynamically because it needs to remain valid after the function finishes.
5. The Reading Process

The core logic can be divided into three stages.
Stage 1: Check the existing stack

Before reading anything new, we check whether stack already contains a newline.

This matters because a previous call may have read several lines at once.

If a newline is already present, we do not need to call read() again. We can immediately extract the next line from the existing data.
Stage 2: Read and concatenate

If stack does not contain a newline, we need to read more data.

We repeatedly call read() and append the valid contents of buffer to stack.

The process continues until:

    A newline is found in stack.
    The end of the file is reached.
    An error occurs.

Because we need to concatenate dynamically allocated strings, we implement our own concatenation function.

The general concatenation process is:

    Calculate the length of the existing stack.
    Allocate enough memory for the old contents, the new buffer contents and the terminating \0.
    Copy the previous stack into the new allocation.
    Append the buffer contents using buffer_len.
    Terminate the resulting string with \0.
    Free the previous stack.
    Return the new string.

If allocation fails, we must handle the error and release any memory that is no longer needed.
Stage 3: Extract the line

Once a newline is found, we separate the next line from the remaining data.

For example, if stack contains:
text

Hello\nMy name is John\n

The returned line is:
text

Hello\n

The remaining stack becomes:
text

My name is John\n

We then return line without discarding the remaining data.

On the next call, we check stack again before reading anything else.

This avoids unnecessary calls to read() and prevents previously read data from being lost.
6. Handling the End of the File

The file does not necessarily end with a newline, so we must account for several cases.
Case 1: The file ends with \n

For example:
text

Hello\n

We return Hello\n.

A subsequent call will return NULL if no more data remains.
Case 2: The file does not end with \n

For example:
text

Hello

If the end of the file is reached while stack still contains characters, those characters form the final line.

We return Hello without adding a newline.

After returning this final line, the remaining state must be cleared so that the next call returns NULL.
Case 3: The file is empty

If the file contains no data, stack remains empty.

The function returns NULL.
Case 4: The file contains data but no newline

The function keeps reading until it reaches the end of the file, accumulating all the data into stack.

Once EOF is reached, it returns the accumulated content as the final line.
Case 5: A read error occurs

If read() returns -1, an error has occurred.

We must release the allocated memory associated with the current operation, reset the relevant state and return NULL.

We must distinguish this case from EOF, where read() returns 0.
7. Handling Memory Correctly

Dynamic memory allocation is central to this project.

Whenever we concatenate strings, we allocate a new block of memory large enough to hold the previous contents and the newly read data.

The old allocation is then freed once its contents have been copied successfully.

We must also account for allocation failures.

If malloc() or calloc() fails, the function must not continue using an invalid pointer. Any memory that is no longer needed must be freed, and the function must return NULL where appropriate.

A static pointer can still be freed. However, freeing its allocated memory does not erase the pointer's stored address automatically.

Therefore, after freeing stack, we should set it to NULL whenever that state is intended to represent an empty stack.

This prevents accidental access to freed memory and makes subsequent calls easier to handle safely.
8. File Descriptors

A file descriptor is an integer used by the operating system to identify an open file or another input/output resource.

The standard file descriptors are:

    0: Standard input (stdin).
    1: Standard output (stdout).
    2: Standard error (stderr).

When a file is opened successfully, the operating system returns a file descriptor. The descriptor is not necessarily greater than 2 in every situation, because standard descriptors can be closed and reused.

The file descriptor is usually obtained through a call such as:
c

fd = open("file.txt", O_RDONLY);

get_next_line() receives a file descriptor as an argument and reads from that descriptor using read().

The caller is responsible for closing the file descriptor when it is no longer needed.
Supporting multiple file descriptors

The mandatory part can use a single static pointer if it only needs to preserve the state for one file descriptor at a time.

However, the bonus part requires the function to handle multiple file descriptors without mixing their data.

For example, if we read from fd1, then from fd2, and then return to fd1, the remaining contents of each file must still be available independently.

To achieve this, we need separate persistent storage for each file descriptor.

One possible solution is a static array of pointers:
c

static char *stack[OPEN_MAX];

The exact implementation depends on the project's requirements and the limits we choose to support.

Another option is a dynamically allocated structure or another suitable data structure that associates each file descriptor with its own state.

A char ** can be used to manage multiple strings, but it does not automatically solve the problem: we must still map each file descriptor to the correct storage position and manage that memory safely.

We must also consider that file descriptor numbers can be reused after a file is closed.
9. The BUFFER_SIZE Question

The project allows BUFFER_SIZE to be changed at compilation time.

If no value is provided, the implementation can use a default value of 42, depending on the project's compilation setup.

The function should not depend on one particular buffer size.
What happens with different values?
BUFFER_SIZE = 1

The function reads one byte at a time.

This should still work correctly, although it may require many calls to read() and therefore run more slowly.

If the test suite times out, the issue may be performance rather than incorrect line extraction.
BUFFER_SIZE = 42

The function reads up to 42 bytes per call. This is a convenient default for testing but has no special significance to the algorithm.
BUFFER_SIZE = 9999

The function should still work if the allocation sizes, concatenation logic and line extraction are implemented correctly.

A larger buffer may allow the function to read multiple lines in a single call.
BUFFER_SIZE = 10000000

The function should still handle the value correctly in principle, but memory usage and performance become more important.

Large allocations may fail, and the implementation must handle that possibility safely.
Why must the implementation work with different buffer sizes?

Because BUFFER_SIZE determines how much data is read at once, not how long a line can be.

A line may be shorter than the buffer, longer than the buffer, or contain data that spans multiple reads.

The algorithm must therefore rely on the actual number of bytes returned by read(), rather than assuming that every read fills the buffer.
10. Functions Needed

The project can be divided into several helper functions.
get_next_line()

The main function. It coordinates reading, concatenation, line extraction and error handling.
Concatenation function

Appends the newly read data to the existing stack, allocating enough memory for the result.
Newline-checking function

Checks whether a string contains \n.

It allows the function to determine whether another read is necessary.
Line-extraction function

Creates and returns the next line, including the newline when one exists.

It must also preserve the data after the first newline.
String-length and copy functions

These helpers can be implemented from scratch if required by the project.

They help manage dynamically allocated strings without relying on prohibited library functions.
11. Splitting the Code

The implementation may be split into helper functions to respect the Norminette rules and make the logic easier to understand.

A useful separation is:

    Reading and concatenating data.
    Checking for a newline.
    Extracting the next line.
    Updating the remaining stack.
    Handling EOF and errors.

One important detail is that if a helper function needs to modify the actual stack pointer, passing char **stack allows it to update the pointer owned by the caller.

Passing only char *stack copies the pointer value, so assigning a new address to that local parameter does not update the caller's pointer.

This distinction is especially useful when splitting the code into smaller functions.
12. Final Algorithm

The complete logic can be summarized as follows:

    Validate the file descriptor and the buffer size.
    Check whether the static stack already contains a complete line.
    If not, read more data into the buffer.
    Append the valid bytes to the stack.
    Repeat until a newline is found, EOF is reached, or an error occurs.
    If a newline exists, extract and return the next line while preserving the remainder.
    If EOF is reached and the stack still contains characters, return those characters as the final line.
    If the stack is empty, return NULL.
    If an error occurs, clean up the relevant memory and return NULL.

The key idea behind Get Next Line is simple: read in chunks, preserve the unread remainder between calls, and return only one line at a time.
13. Implementation Notes and Questions

During development, several questions are worth investigating:

    How does the implementation behave when BUFFER_SIZE is 1?
    Does it handle very large buffer sizes without memory errors?
    Does the bonus implementation maintain independent state for multiple file descriptors?
    Is the memory freed correctly when EOF or an error occurs?
    Does the function return the final line correctly when the file does not end with \n?
    Can the code be simplified while still respecting the Norminette rules?

These questions help verify both the correctness of the algorithm and the reliability of the memory management.