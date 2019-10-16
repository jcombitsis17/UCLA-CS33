	.file	"creadcmov.c"
	.text
	.p2align 4,,15
	.globl	creadcmov
	.type	creadcmov, @function
creadcmov:
.LFB0:
	.cfi_startproc
	leaq	-8(%rdi), %rdx
	testq	%rdi, %rdi
	movq	$-1, %rax
	cmovne	%rdx, %rax
	movq	(%rax), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	creadcmov, .-creadcmov
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-28)"
	.section	.note.GNU-stack,"",@progbits
