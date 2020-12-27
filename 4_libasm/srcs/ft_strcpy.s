; /* *********************************************************************** */
; /*                                                                         */
; /*                                                     :::      ::::::::   */
; /*   ft_strcpy.s                                     :+:      :+:    :+:   */
; /*                                                 +:+ +:+         +:+     */
; /*   By: mihykim <mihykim@student.42seoul.kr>    +#+  +:+       +#+        */
; /*                                             +#+#+#+#+#+   +#+           */
; /*   Created: 2020/11/12 08:15:17 by mihykim        #+#    #+#             */
; /*   Updated: 2020/11/12 08:36:17 by mihykim       ###   ########.fr       */
; /*                                                                         */
; /* *********************************************************************** */

section  .text
  global  _ft_strcpy

_ft_strcpy:
  mov    rcx, 0                ; i = 0
  mov    rdx, 0                ; tmp = NULL
  cmp    rsi, 0                ; if (src == NULL)
  jz     end                    ; break
  jmp    compare

compare:
  mov    dl, BYTE [rsi + rcx]  ; tmp = src[i]
  mov    BYTE [rdi + rcx], dl  ; dst[i] = tmp
  cmp    dl, 0                 ; if (src[i] == '\0')
  jz     end                   ; break
  inc    rcx                   ; i++
  jmp    compare

end:
  mov    rax, rdi              ; return dst
  ret
