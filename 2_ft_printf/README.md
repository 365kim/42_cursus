# ft_printf

### :bulb: Evaluation Log
1. 20/04/11 : KO
    - `1/12 correct functions` :wrench: _...trying to figure out_
    - `bonus compile error` :wrench: _...added make bonus rule in Makefile_
2. 20/04/00 : 
    - **00 score** (mandatory 00 + bonus 00)
***

### :bulb: Objective
- to recode __printf__ fuction in C in the well-structured and extensible way
- to learn how to use `variadic arguments`
***

### :bulb: Codes
1. Mandatory Part: [***Makefile***](./Makefile), [***ft_printf.c***](./ft_printf.c), [***ft_printf.h***](./ft_printf.h), [***1.parse***](./f1_parse.c), [***2.write***](./f2_write.c), [***3.assist***](./f3_assist.c)
    - ***conversion***: c, s, p, d, i u, x, X, %
    - ***flag***: -, 0, ., *

2. Bonus Part: [***UTF-8***](./ft_atouni.c)
    - ***conversion***(one or more): n, ~f~, ~g~, ~e~
    - ***length modifier***(one or more): l, ll, h, hh
    - ***flag***(all): #, ' ',+
    - You don’t need to do all of them
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
