This project has been created as part
of the 42 curriculum by <yasmail>.

Description--
The ft_printf project is a custom implementation of the standard C printf function.
The goal of this project is to mimic the behavior of printf and handle a variety of data types and format specifiers,
Such as:
-integers
-strings
-characters
-unsigned types
-pointers
The project aims to offer a simplified,
yet flexible version of printf while maintaining efficiency and robustness,
especially when handling special formats such as ssize_t

--End description

Instructions--

Clone the repository to your local machine.
"
$ git clone <repository_url>
$ cd ft_printf
"

Compile the project using the make command:
"
$ make
"
Test the program with a sample C file (e.g., main.c) to check its functionality:
"
$ gcc -o test main.c libftprintf.a
$ ./test
"

libftprintf.a: static library containing the custom ft_printf function
include main.c to test cases to verify that ft_printf works as expected

--End Instruction

Resources--

AI Assistance:

AI was used for code optimization, specifically for detecting and resolving segmentation faults.

AI helped in understanding and explaining how the va_list works in C for variadic functions,
and the proper handling of variable argument types.

--End Resources

Technical Choices--

The program was designed to closely follow the standard printf function's behavior,
supporting multiple format specifiers and handling edge cases.

The primary data structure used in this project is the va_list,
which is key to managing the variable arguments passed to ft_printf.

A set of header functions was created to implement various checks,
helping avoid unexpected behavior.
Without these checks, the system may not work as intended.
--End Technical Choices

Limitations--

Error handling may be limited in certain edge cases.

--End limitations