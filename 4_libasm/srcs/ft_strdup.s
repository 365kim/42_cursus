; /* *********************************************************************** */
; /*                                                                         */
; /*                                                     :::      ::::::::   */
; /*   ft_strdup.s                                     :+:      :+:    :+:   */
; /*                                                 +:+ +:+         +:+     */
; /*   By: mihykim <mihykim@student.42seoul.kr>    +#+  +:+       +#+        */
; /*                                             +#+#+#+#+#+   +#+           */
; /*   Created: 2020/11/12 08:37:10 by mihykim        #+#    #+#             */
; /*   Updated: 2020/11/12 08:58:53 by mihykim       ###   ########.fr       */
; /*                                                                         */
; /* *********************************************************************** */

section  .text
  global  _ft_strdup
  extern  _malloc
  extern  _ft_strlen
  extern  _ft_strcpy

_ft_strdup:  
    cmp    rdi, 0             ; if (src == NULL)
    je     manage_error
    call   _ft_strlen         ; ft_strlen(src)
    push   rdi                ; keep src
    mov    rdi, rax           ; i = len
    inc    rdi                ; i++
    call   _malloc            ; malloc (len + 1)
    cmp    rax, 0             ; if (str == NULL)
    je     manage_error
    pop    rsi                ; pop src
    mov    rdi, rax
    call   _ft_strcpy         ; ft_strcpy(str, src)
    jmp    end

manage_error:
      mov    rax, 0           ; return (0)

end:
      ret                     ; return (str)
