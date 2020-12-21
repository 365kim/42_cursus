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
  global _ft_write;
  extern ___error

_ft_read:
	mov		rax, 0x2000004
	syscall
	jc		_err
	ret

_err:
	mov   rdx rax
	call	___error
	mov		[rax], rdx
	mov		rax, -1
	ret