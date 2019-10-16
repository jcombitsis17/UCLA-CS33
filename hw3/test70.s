	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_proc                   ## -- Begin function proc
	.p2align	4, 0x90
_proc:                                  ## @proc
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movq	8(%rdi), %rax
	movq	(%rax), %rcx
	movq	(%rcx), %rcx
	subq	8(%rax), %rcx
	movq	%rcx, (%rdi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
