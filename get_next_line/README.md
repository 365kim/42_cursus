# get_next_line

### :bulb: Evaluation Log
1. 20/00/00 : OK
    - **100 score** (mandatory 100 + bonus 0)
***

### :bulb: Objective
- to code a function that returns a line ending with a newline, read from a file descriptor
- to learn a highly interesting new concept in C programming: `static variables`
***

### :bulb: Codes
1. Mandatory Part: [***gnl.c***](./get_next_line.c), [***gnl_utils.c***](./get_next_line_utils.c), [***gnl.h***](./get_next_line.h)
    - ***function description*** : returns a line read from a file descriptor, without the newline
    - ***compile option*** : gcc -Wall -Wextra -Werror `-D BUFFER_SIZE=32` get_next_line.c get_next_line_utils.c
    - since libft is not allowed, up to 5 functions can be added in gnl_utils.c (don't know why :sob:)

2. Bonus Part: [***gnl_bonus.c***](./get_next_line_bonus.c), [***gnl_utils_bonus.c***](./get_next_line_utils_bonus.c), [***gnl_bonus.h***](./get_next_line_bonus.h)
    - ***requirement 1***: to succeed get_next_line with a single static variable.
    - ***requirement 2***: to be able to manage multiple file descriptors with get_next_line without losing the reading thread on each of the descriptors.
    
