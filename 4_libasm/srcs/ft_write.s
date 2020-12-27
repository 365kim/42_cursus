; /* *********************************************************************** */
; /*                                                                         */
; /*                                                     :::      ::::::::   */
; /*   ft_write.s                                      :+:      :+:    :+:   */
; /*                                                 +:+ +:+         +:+     */
; /*   By: mihykim <mihykim@student.42seoul.kr>    +#+  +:+       +#+        */
; /*                                             +#+#+#+#+#+   +#+           */
; /*   Created: 2020/11/15 15:30:17 by mihykim        #+#    #+#             */
; /*   Updated: 2020/11/15 15:49:17 by mihykim       ###   ########.fr       */
; /*                                                                         */
; /* *********************************************************************** */

section .text
  global _ft_write
  extern ___error

_ft_write:
  mov      rax, 0x2000004  ; func = write()
  syscall                  ; func()
  jc       manage_error    ; if (ret < 0)
  ret

manage_error:
  push     rax
  call     ___error
  pop      rdx
  mov      [rax], rdx
  mov      rax, -1
  ret
