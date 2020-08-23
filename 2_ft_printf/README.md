# ft_printf

### :bulb: Evaluation Log
1. 20/04/11
    - `01/12 correct functions` & `bonus compile error`
2. 20/04/13
    - `10/12 correct functions` & `bonus seg-fault`
3. 20/04/17
    - `11/12 correct functions` & `bonus seg-fault`
4. 20/05/29
    - **110 score** _(mandatory 100 + bonus 10)_
***

### :bulb: Objective
- to recode __printf__ fuction in C in the well-structured and extensible way

- to learn how to use `variadic arguments`
***

### :bulb: Codes
0. Preview to understand printf's behavior
    - [***%c***](./examples/%25c), [***%s***](./examples/%25s), [***%p***](./examples/%25p), [***%d***](./examples/%25d), [***%u***](./examples/%25u), [***%x***](./examples/%25x), [***%%***](./examples/%25%25)
1. Mandatory Part
    - ***conversion***: c, s, p, d, i u, x, X, %
    - ***flag***: -, 0, ., *
    - [***Makefile***](./ft_printf/Makefile), [***ft_printf.c***](./ft_printf/ft_printf.c), [***ft_printf.h***](./ft_printf/ft_printf.h)
    - [***parse_all***](./ft_printf/parse_all.c), [***manage_box.c***](./ft_printf/manage_box.c), [***manage_int_sign.c***](./ft_printf/manage_int_sign.c)
    - [***print%c***](./ft_printf/print_1_char.c), [***print%s***](./ft_printf/print_2_string.c), [***print%d%i***](./ft_printf/print_3_int.c), [***print%u***](./ft_printf/print_4_unsigned_int.c), [***print%x%X***](./ft_printf/print_5_hexa.c), [***print%p***](./ft_printf/print_6_pointer.c), [***print%%***](./ft_printf/print_7_percent.c)

2. Bonus Part: 
    - ***conversion***(one or more): n, ~f~, ~g~, ~e~
    - ***length modifier***(one or more): l, ll, h, hh
    - ***flag***(all): #, ' ',+
    - [***store_nbyte***](./ft_printf/store_8_nbyte.c), [***convert_to_UTF-8***](./ft_printf/libft/ft_atouni.c), [***pre_process***](./ft_printf/pre_process.c)
---

### :bulb: Useful Links
- 42TESTERS by [_Mazoise_](https://github.com/Mazoise/42TESTERS-PRINTF)
    ```
    git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
    ```
- pft by [_gavinfielder_](https://github.com/gavinfielder)
    ```
    git clone https://github.com/gavinfielder/pft.git pft && echo "pft/" >> .gitignore
    ```
- pft_2019 by [_cclaude42_](https://github.com/cclaude42/PFT_2019)
    ```
    git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
    ```
- printf_lover_v2 by [_charMstr_](https://github.com/charMstr/printf_lover_v2)
    ```
    git clone https://github.com/charMstr/printf_lover_v2.git
    ```
