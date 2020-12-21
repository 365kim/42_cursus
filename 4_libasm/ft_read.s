; /* *********************************************************************** */
; /*                                                                         */
; /*                                                     :::      ::::::::   */
; /*   ft_read.s                                       :+:      :+:    :+:   */
; /*                                                 +:+ +:+         +:+     */
; /*   By: mihykim <mihykim@student.42seoul.kr>    +#+  +:+       +#+        */
; /*                                             +#+#+#+#+#+   +#+           */
; /*   Created: 2020/11/15 15:30:17 by mihykim        #+#    #+#             */
; /*   Updated: 2020/11/15 15:49:17 by mihykim       ###   ########.fr       */
; /*                                                                         */
; /* *********************************************************************** */

section .text
	global _ft_read
	extern ___error

_ft_read:
	mov		rax, 0x2000003
	syscall
	jc		err
	ret

err:
	mov   rdx rax
	call	___error
	mov		[rax], rdx
	mov		rax, -1
	ret