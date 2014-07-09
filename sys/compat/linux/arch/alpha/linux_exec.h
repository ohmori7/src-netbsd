/*	$NetBSD: linux_exec.h,v 1.12 2014/02/09 16:41:42 chs Exp $	*/

/*-
 * Copyright (c) 1998 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Eric Haszlakiewicz.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _ALPHA_LINUX_EXEC_H
#define _ALPHA_LINUX_EXEC_H

#include <sys/exec_aout.h>
#include <sys/exec_elf.h>

#define LINUX_M_ALPHA		MID_ALPHA
#define LINUX_MID_MACHINE	LINUX_M_ALPHA

/*
 * LINUX_ATEXIT_SIGNATURE enable the atexit_signature test. See
 * sys/compat/linux/common/linux_exec_elf32.c:linux_atexit_signature()
 */
#define	LINUX_ATEXIT_SIGNATURE	1

/*
 * Alpha specific ELF defines.
 */
#define LINUX_ELF_AUX_ARGSIZ \
	(howmany(sizeof(Aux64Info) * LINUX_ELF_AUX_ENTRIES, sizeof(char *)) + LINUX_RANDOM_BYTES)

#define linux_exec_setup_stack	exec_setup_stack

#endif /* !_ALPHA_LINUX_EXEC_H */
