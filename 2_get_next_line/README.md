# get_next_line

### :bulb: Evaluation Log
1. 20/04/10 : OK
    - **107 score** (mandatory 100 + bonus 7)
***

### :bulb: Objective
- to code a function that returns a line ending with a newline, read from a file descriptor
- to learn a highly interesting new concept in C programming: `static variables`
***

### :bulb: Codes
1. Mandatory Part: [***gnl.c***](./get_next_line.c), [***gnl_utils.c***](./get_next_line_utils.c), [***gnl.h***](./get_next_line.h)
    - ***function description*** : returns a line read from a file descriptor, without the newline
    - ***compile option*** : gcc -Wall -Wextra -Werror `-D BUFFER_SIZE=32` get_next_line.c get_next_line_utils.c
    - since libft is not allowed, up to 5 functions can be added in gnl_utils.c

2. Bonus Part: [***gnl_bonus.c***](./get_next_line_bonus.c), [***gnl_utils_bonus.c***](./get_next_line_utils_bonus.c), [***gnl_bonus.h***](./get_next_line_bonus.h)
    - ***requirement 1***: to succeed get_next_line with a single static variable.
    - ***requirement 2***: to be able to manage multiple file descriptors with get_next_line without losing the reading thread on each of the descriptors.
---

### :bulb: Useful Links
- gnlkiller by [_DontBreakAlex_](https://github.com/DontBreakAlex/gnlkiller)
    ```
    git clone https://github.com/DontBreakAlex/gnlkiller.git ; cd gnlkiller; cp ../get_next_line.c .; cp ../get_next_line_utils.c .; cp ../get_next_line.h .; ./run.sh;
    ```
- GNL_lover by [_charMstr_](https://github.com/charMstr/GNL_lover)
    ```
    git clone https://github.com/charMstr/GNL_lover.git
    ```
- gnl-war-machine by [_Alexandre94H_](https://github.com/Alexandre94H/gnl-war-machine-v2019)
    ```
    git clone https://github.com/Alexandre94H/gnl-war-machine-v2019.git
    ```
- 42TESTERS-GNL by [_Mazoise_](https://github.com/Mazoise/42TESTERS-GNL)
    ```
    git clone https://github.com/Mazoise/42TESTERS-GNL.git
    ```
