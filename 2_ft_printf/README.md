# ft_printf

### :bulb: Evaluation Log
1. 20/04/11
    - `01/12 correct functions` & `bonus compile error`
2. 20/04/13
    - `10/12 correct functions` & `bonus seg-fault`
3. 20/04/17
    - `11/12 correct functions` & `bonus seg-fault`
4. 20/05/00
    - **00 score** (mandatory 00 + bonus 00)
***

### :bulb: Objective
- to recode __printf__ fuction in C in the well-structured and extensible way

- to learn how to use `variadic arguments`
***

### :bulb: Codes
0. Preview to understand printf's behavior
    - [%c](./examples/%c), [%s](./examples/%s), [%p](./examples/%p), [%d](./examples/%d), [%u](./examples/%u), [%x](./examples/%x), [%%](./examples/%%)
1. Mandatory Part
    - ***conversion***: c, s, p, d, i u, x, X, %
    - ***flag***: -, 0, ., *
    - [***Makefile***](./Makefile), [***ft_printf.c***](./ft_printf.c), [***ft_printf.h***](./ft_printf.h)
    - [***parse_all***](./parse_all.c), [***manage_box.c***](./manage_box.c), [***manage_int_sign.c***](./manage_int_sign.c)
    - [***1_print_%c***](./print_1_char.c), [***2_print_%s***](./print_2_string.c), [***3_print_%di***](./print_3_int.c), [***4_print_%u***](./print_4_unsigned_int.c), [***5_print_%xX***](./print_5_hexa.c), [***6_print_%p***](./print_6_pointer.c), [***7_print_%%***](./print_7_percent.c)

2. Bonus Part: 
    - ***conversion***(one or more): n, ~f~, ~g~, ~e~
    - ***length modifier***(one or more): l, ll, h, hh
    - ***flag***(all): #, ' ',+
    - [***store_nbyte***](./store_8_nbyte.c)
    - [***UTF-8***](./ft_atouni.c)
    - [***pre_process***](./pre_process.c)
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
