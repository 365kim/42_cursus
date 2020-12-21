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
	mov	rax, 0 ; set rax to 0
	jmp	while_loop

while_loop:
	cmp	byte [rdi + rax], 0 ; Compare and precede any jump instruction
	je	end ; Jump to 'end' if equal (rdi[rax] == NULL)
	inc	rax ; Do rax++
	jmp	while_loop

end:
	ret ; Pop and jmp EIP