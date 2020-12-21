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

_ft_strdup:
	call	_ft_strlen	; Set rax to strlen(str)
	inc		rax					; Set (len + 1) for '\0'
	push	rdi
	mov		rdi, rax
	call	_malloc			; Allocate (len + 1) in rax
	pop		rbx					; rbx == str
	mov		rsi, rbx
	mov		rdi, rax
	call	_ft_strcpy
	ret