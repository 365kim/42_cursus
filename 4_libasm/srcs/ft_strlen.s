; /* *********************************************************************** */
; /*                                                                         */
; /*                                                     :::      ::::::::   */
; /*   ft_strlen.s                                     :+:      :+:    :+:   */
; /*                                                 +:+ +:+         +:+     */
; /*   By: mihykim <mihykim@student.42seoul.kr>    +#+  +:+       +#+        */
; /*                                             +#+#+#+#+#+   +#+           */
; /*   Created: 2020/11/10 15:15:17 by mihykim        #+#    #+#             */
; /*   Updated: 2020/11/11 08:49:17 by mihykim       ###   ########.fr       */
; /*                                                                         */
; /* *********************************************************************** */

section .text
  global _ft_strlen

_ft_strlen:
  mov  rax, 0                 ; i = 0
  jmp  get_length

get_length:
  cmp  byte [rdi + rax], 0    ; if (str[i] == '\0')
  je   end                    ; break
  inc  rax                    ; i++
  jmp  get_length

end:
  ret                         ; return i
