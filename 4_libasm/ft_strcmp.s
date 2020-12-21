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

section .text
	global _ft_strcmp

_ft_strcmp:
	mov		rcx, 0
	jmp   while_loop

while_loop:
	mov		al, BYTE [rdi + rcx] ; al = dst[i]
	mov		bl, BYTE [rsi + rcx] ; bl = src[i]
	cmp		al, 0
	je		end
	cmp		bl, 0
	je		end
	cmp		al, bl
	jne		end
	inc		rcx ; i++
	jmp		while_loop

end:
	mov	  rax, al
	mov	  rbx, bl
	sub		rax, rbx
	ret