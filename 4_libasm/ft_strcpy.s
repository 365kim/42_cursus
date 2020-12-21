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

section .text
	global _ft_strcpy

_ft_strcpy:
	mov		rcx, 0
	jmp		while_loop

while_loop:
	cmp		BYTE [rsi + rcx], 0
	je		end
	mov		bl, [rsi + rcx]
	mov 	[rdi + rcx], bl
	inc		rcx
	jmp		while_loop

end:
	mov		bl, 0
	mov		[rdi + rcx], bl
	mov		rax, rdi
	ret