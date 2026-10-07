*This project has been created as part of the 42 curriculum by pokuzmic.*

# Libft

## DESCRIPTION
**Libft** project is aimed to create a C library developed as a part of the 42 curriculum.
The goal is recreate a collection of functions from the standard C library and to carry out additional functions that can be used in future projects. This will help me to understad how these functions worsk and learn how to use them effectively.

The resulting library is called `libft.a` and can be linked to other C programs.
The library is divided into several groups of functions.

### Library description

`libft.a` is a static library containing all functions implemented for the project.

The library is accompanied by the header file `libft.h`, which contains the required function prototypes and the definition of the linked-list structure.

### Library Overview

#### FIRST - Character checks and conversions
These functions reproduce operations for checking and converting characters. The values returned are nonzero if the character c falls into the tested class, and zero if not:

ft_isalpha - (int ft_isalpha(int c)) - checks for an alphabetic character.

ft_isdigit - (int ft_isdigit(int c)) - checks for a digit (0 through 9).

ft_isalnum - (int ft_isalnum(int c)) - checks for an alphanumeric character; it is equivalent to (isalpha || isdigit).

ft_isascii - (int ft_isascii(int c)) - checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.

ft_isprint - (int ft_isprint(int c)) - checks for any printable character including space.

ft_toupper - (int ft_toupper(int c)) - If c is a lowercase letter, toupper() returns its uppercase equivalent, if an uppercase representation exists in the current locale.  Otherwise, it returns c.

ft_tolower - (int ft_tolower(int c)) - If c is an uppercase letter, tolower() returns its lowercase equivalent, if a lowercase representation exists in the current locale.  Otherwise, it returns c.

#### SECOND - String functions
These functions provide common string manipulation operations:

ft_strlen - (size_t ft_strlen(const char *str)) -  The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0'). It returns the number or bytes in the string pointed to by str.

ft_strlcpy - (size_t	ft_strlcpy(char *dst, const char *src, size_t size)) - copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.The strlcpy() function returns the total length of the string it tried to create. For strlcpy() that means the length of src. 

ft_strlcat - (size_t	ft_strlcat(char *dst, const char *src, size_t size)) - appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result. The strlcat() function returns the total length of the string they tried to create. For strlcat() that means the initial length of dst plus the length of src. 

ft_strchr - (char *ft_strchr(const char *s, int c)) - The strchr() function returns a pointer to the first occurrence of the character c in the string s or NULL if the character is not found.

ft_strrchr - (char *ft_strrchr(const char *s, int c)) - The strrchr() function returns a pointer to the last occurrence of the character c in the string s or NULL if the character is not found.

ft_strncmp - (int ft_strncmp(const char *s1, const char *s2, size_t n)) - The strncmp() function shall compare not more than n bytes (bytes that follow a NUL character are not compared) from the array pointed to by s1 to the array pointed to by s2. Upon successful completion, strncmp() shall return an integer greater than, equal to, or less than 0, if the possibly null-terminated array pointed to by s1 is greater than, equal to, or less than the possibly null-terminated array pointed to by s2 respectively.

ft_strnstr - (char *ft_strnstr(const char *box, const char *needle, size_t len)) - is a non-standard C library function that finds the first occurrence of a substring within a string, searching at most a specified number of characters. Returns a pointer to the first character of the first occurrence of needle, NULL if the substring is not found, or box if little is an empty string.

ft_strdup - (char *ft_strdup(const char *s)) - The strdup() function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string is obtained with malloc. It returns NULL if insufficient memory was available.

#### THIRD - Memory functions
These functions are used to manipulate memory areas:

ft_memset - (void *ft_memset(void *str, int c, size_t n)) - The memset() function fills the first n bytes of the memory area pointed to by str with the constant byte c. Returns a pointer to the memory area str.

ft_bzero - (void ft_bzero(void *s, size_t n)) - The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area. No return value.

ft_memcpy - (void *ft_memcpy(void *dest, const void *src, size_t n)) - The memcpy() function copies n bytes from memory area src to memory area dest. The memory areas must not overlap. Return a pointer to dest.

ft_memmove - (void *ft_memmove(void *dest, const void *src, size_t n)) - The memmove() function copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest Return a pointer to dest.

ft_memchr - (void *ft_memchr(const void *s, int c, size_t n)) - The memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char. Return a pointer to the matching byte or NULL if the character does not occur in the given memory area.

ft_memcmp - (int ft_memcmp(const void *s1, const void *s2, size_t n)) - compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2. Returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2.

ft_calloc - (void *ft_calloc(size_t count, size_t size)) - shall allocate unused space for an array of count elements each of whose size in bytes is size. The space shall be initialized to all bits 0. Upon successful completion, calloc() shall return a pointer to the allocated space. Otherwise, it shall return a null pointer.

#### FOURTH - conversion functions
The library provides functions for converting between strings and integers:

ft_atoi - (int	ft_atoi(const char *nptr)) - The atoi() function converts the initial portion of the string pointed to by nptr to int. Returns the converted value or 0 on error.

ft_itoa - (char	*ft_itoa(int n)) - allocates memory (using malloc(3)) and returns a string representing the integer received as an argument. Returns The string representing the integer or NULL if the allocation fails.

#### FIFTH - additional string utilities
These functions extend the functionality of the standard C library:

ft_substr - (char *ft_substr(char const *s, unsigned int start size_t len)) - Allocates memory (using malloc(3)) and returns a substring from the string ’s’. The substring starts at index ’start’ and has a maximum length of ’len’. Return substring or NULL if the allocation fails.

ft_strjoin - (char *ft_strjoin(char const *s1, char const *s2)) - Allocates memory (using malloc(3)) and returns a new string, which is the result of concatenating ’s1’ and ’s2’. Return the new string or NULL if the allocation fails.

ft_strtrim - (char *ft_strtrim(char const *s1, char const *set)) - Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters from ’set’ removed from the beginning and the end. Returns the trimmed string or NULL if the allocation fails.

ft_split - (char **ft_split(char const *s, char c)) - Allocates memory (using malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. Each string in the returned array is allocated independently. The array of pointers itself is also allocated dynamically. The returned array must be NULL terminated. Returns array of new strings resulting from the split or NULL if any allocation fails.

ft_strmapi - (char * ft_strmapi(char const * s, char (*f)(unsigned int, char))) - Applies the function f to each character of the string s, passing its index as the first argument and the character itself as the second. A new string is created (using malloc(3)) to store the results from the successive applications of f. The string created from the successive applications of ’f’ or NULL if any allocation fails.
 
ft_strteri - (void ft_striteri(char * s, void (* f)(unsigned int, char*))) - Applies the function ’f’ to each character of the string passed as argument, passing its index as the first argument. Each character is passed by address to ’f’ so it can be modified if necessary. No return.

#### SIXTH - File descriptor output
These functions write data to a specified file descriptor:

ft_putchar_fd - (void ft_putchar_fd(char c, int fd)) - Outputs the character ’c’ to the specified file descriptor. No return.

ft_putstr_fd - (void ft_putstr_fd(char *s, int fd)) - Outputs the string ’s’ to the specified file descriptor. No return.

ft_putendl_fd - (void ft_putendl_fd(char *s, int fd)) - Outputs the string ’s’ to the specified file descriptor followed by a newline. No return.

ft_putnbr_fd - (void ft_putnbr_fd(int n, int fd)) - Outputs the integer ’n’ to the specified file descriptor. No return.

#### SEVENTH - Linked list functions
The bonus part of the project provides functions for manipulating singly linked lists:

ft_lstnew - (t_list *ft_lstnew(void *content)) - Allocates memory (using malloc(3)) and returns a new node. The ’content’ member variable is initialized with the given parameter ’content’. The variable ’next’ is initialized to NULL. Returns pointer to a new node.

ft_lstadd_front - (void ft_lstadd_front(t_list **lst, t_list *new)) - Adds the node ’new’ at the beginning of the list. No return.

ft_lstsize - (int ft_lstsize(t_list *lst)) - Counts the number of nodes in the list. Returns the length of the list.

ft_lstlast - (t_list *ft_lstlast(t_list *lst)) - Returns the last node of the list.

ft_lstadd_back - (void ft_lstadd_back(t_list **lst, t_list *new)) - Adds the node ’new’ at the end of the list. No return.

ft_lstdelone - (void ft_lstdelone(t_list * lst, void (* del)(void*))) - Takes a node as parameter and frees its content using the function ’del’. Free the node itself but does NOT free the next node. No return.

ft_lstclear - (void ft_lstclear(t_list ** lst, void (* del)(void*))) - Deletes and frees the given node and all its successors, using the function ’del’ and free(3). Finally, set the pointer to the list to NULL. No return.

ft_lstiter - (void ft_lstiter(t_list * lst, void (* f)(void *))) - Iterates through the list ’lst’ and applies the function ’f’ to the content of each node. No return.

ft_lstmap - (t_list * ft_lstmap(t_list * lst, void * (* f)(void * ),void (*del)(void *))) - Iterates through the list ’lst’, applies the function ’f’ to each node’s content, and creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed. Returns the new list or NULL if the allocation fails.

## INTRSUCTIONS

### Compilation
The library is compiled using `make`. The `Makefile` compiles all source files with the required compiler flags and creates the static library `libft.a`.

To compile the project: `make all`
This command creates: `libft.a`
The project is compiled with: -Wall -Wextra -Werror

### Makefile commands
The following commands are available:
`make all` - Compiles all source files and creates the libft.a static library.
`make clean` - Removes all object files (.o).
`make fclean` - Removes all object files and the libft.a library.
`make re` - Removes all generated files and recompiles the entire library.

### Usage
The library can then be reused in other C projects by including libft.h and linking against libft.a.

## RESOURCES
### Resources
The following resources were used to understand the requirements of the project, the behavior of standard C library functions, memory management, and linked lists:

**42 Libft Subject** - the official project subject provided by 42, used as the main reference for the project requirements and expected function behavior.

**Linux/Unix man pages** - used as a reference for standard library and system functions.

**Youtube Tutorials** - https://www.youtube.com/watch?v=nxCnKVMGAFs&t=355s; https://www.youtube.com/watch?v=DGwdAQauEV4; https://www.youtube.com/watch?v=RJzbA6Fmk8I; https://www.youtube.com/watch?v=ihIJRxgcRQ0

**Geeksforgeeks website** - to understand linked lists, static functions and dynamic memory allocation

**Book C IN A NUTSHELL** - from 42 Prague library

### AI Usage
AI tools were used as an learning resource during the development of this project.

AI was used for: clarifying concepts related to pointers and memory management; identifying possible edge cases and testing scenarios; helping understand compiler errors and warnings.

AI was not used to replace the implementation of the library.

