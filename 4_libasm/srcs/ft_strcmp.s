; /* *********************************************************************** */
; /*                                                                         */
; /*                                                     :::      ::::::::   */
; /*   ft_strcmp.s                                     :+:      :+:    :+:   */
; /*                                                 +:+ +:+         +:+     */
; /*   By: mihykim <mihykim@student.42seoul.kr>    +#+  +:+       +#+        */
; /*                                             +#+#+#+#+#+   +#+           */
; /*   Created: 2020/11/12 08:09:17 by mihykim        #+#    #+#             */
; /*   Updated: 2020/11/11 08:48:17 by mihykim       ###   ########.fr       */
; /*                                                                         */
; /* *********************************************************************** */

section  .text
  global  _ft_strcmp

_ft_strcmp:  
  mov    rcx, 0
  mov    rdx, 0
  cmp    rdi, 0                ; if (str1 == NULL)
  jz     input_is_null
  cmp    rsi, 0                ; if (str2 == NULL)
  jz     input_is_null
  jmp    compare

input_is_null:
  cmp    rdi, rsi
  jz     is_equal              ; str1 == NULL && str2 == NULL
  jg     is_greater            ; str1 == NULL
  jmp    is_fewer              ; str2 == NULL

compare:
  cmp    BYTE [rdi + rcx], 0   ; if (str1[i] == '\0')
  je     get_difference
  cmp    BYTE [rsi + rcx], 0   ; if (str2[i] == '\0')
  je     get_difference
  mov    dl, BYTE [rsi + rcx]
  cmp    BYTE [rdi + rcx], dl  ; if (str1[i] == str2[i])
  jne    get_difference
  inc    rcx                   ; i++
  jmp    compare

get_difference:
  mov    dl, BYTE [rdi + rcx]
  sub    dl, BYTE [rsi + rcx]
  cmp    dl, 0                 ; if (str1[i] - str2[i] == 0)
  jz     is_equal
  jg     is_greater
  jl     is_fewer

is_equal:
  mov    rax, 0                ; return 0
  ret

is_greater:
  mov    rax, 1                ; return 1
  ret

is_fewer:
  mov    rax, -1               ; return -1
  ret
