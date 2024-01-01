	.file	"Tree.c"
	.text
	.globl	root
	.bss
	.align 8
	.type	root, @object
	.size	root, 8
root:
	.zero	8
	.globl	par
	.align 8
	.type	par, @object
	.size	par, 8
par:
	.zero	8
	.globl	loc
	.align 8
	.type	loc, @object
	.size	loc, 8
loc:
	.zero	8
	.section	.rodata
.LC0:
	.string	"Enter the item to insert: "
.LC1:
	.string	"%d"
	.text
	.globl	insert
	.type	insert, @function
insert:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	$24, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-16(%rbp), %rax
	movq	$0, 16(%rax)
	movl	-28(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movq	root(%rip), %rax
	testq	%rax, %rax
	jne	.L2
	movq	-16(%rbp), %rax
	movq	%rax, root(%rip)
	jmp	.L1
.L2:
	movq	root(%rip), %rax
	movq	%rax, -24(%rbp)
	jmp	.L4
.L8:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movl	-28(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L5
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L6
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L4
.L6:
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L1
.L5:
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movl	-28(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L4
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L7
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L4
.L7:
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 16(%rax)
	jmp	.L1
.L4:
	cmpq	$0, -24(%rbp)
	jne	.L8
.L1:
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	insert, .-insert
	.section	.rodata
.LC2:
	.string	"%d "
	.text
	.globl	preorder
	.type	preorder, @function
preorder:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L14
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	preorder
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	preorder
	jmp	.L11
.L14:
	nop
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	preorder, .-preorder
	.globl	inorder
	.type	inorder, @function
inorder:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L18
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	inorder
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	inorder
	jmp	.L15
.L18:
	nop
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	inorder, .-inorder
	.globl	postorder
	.type	postorder, @function
postorder:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L22
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	postorder
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	postorder
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L19
.L22:
	nop
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	postorder, .-postorder
	.globl	searchloc
	.type	searchloc, @function
searchloc:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movq	$0, loc(%rip)
	movq	$0, par(%rip)
	movq	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	movq	root(%rip), %rax
	testq	%rax, %rax
	je	.L38
	movq	root(%rip), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jne	.L26
	movq	root(%rip), %rax
	movq	%rax, loc(%rip)
	jmp	.L23
.L26:
	movq	root(%rip), %rax
	movq	%rax, -16(%rbp)
	movq	root(%rip), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jle	.L27
	movq	root(%rip), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L28
.L32:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jne	.L29
	movq	-8(%rbp), %rax
	movq	%rax, loc(%rip)
	movq	-16(%rbp), %rax
	movq	%rax, par(%rip)
	jmp	.L23
.L29:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jle	.L30
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L28
.L30:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jge	.L31
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L28
.L31:
	movq	$0, par(%rip)
	movq	$0, loc(%rip)
	jmp	.L23
.L28:
	cmpq	$0, -8(%rbp)
	jne	.L32
	movq	-16(%rbp), %rax
	movq	%rax, par(%rip)
	movq	$0, loc(%rip)
	jmp	.L23
.L27:
	movq	root(%rip), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jge	.L23
	movq	root(%rip), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L33
.L37:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jne	.L34
	movq	-8(%rbp), %rax
	movq	%rax, loc(%rip)
	movq	-16(%rbp), %rax
	movq	%rax, par(%rip)
	jmp	.L23
.L34:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jle	.L35
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L33
.L35:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -20(%rbp)
	jge	.L36
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L33
.L36:
	movq	$0, par(%rip)
	movq	$0, loc(%rip)
	jmp	.L23
.L33:
	cmpq	$0, -8(%rbp)
	jne	.L37
	movq	-16(%rbp), %rax
	movq	%rax, par(%rip)
	movq	$0, loc(%rip)
	jmp	.L23
.L38:
	nop
.L23:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	searchloc, .-searchloc
	.globl	maximum
	.type	maximum, @function
maximum:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L40
	movl	-4(%rbp), %eax
	jmp	.L41
.L40:
	movl	-8(%rbp), %eax
.L41:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	maximum, .-maximum
	.globl	leaf
	.type	leaf, @function
leaf:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L43
	movl	$0, %eax
	jmp	.L44
.L43:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L45
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L45
	movl	$1, %eax
	jmp	.L44
.L45:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	leaf
	movl	count.0(%rip), %edx
	addl	%edx, %eax
	movl	%eax, count.0(%rip)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	leaf
	movl	count.0(%rip), %edx
	addl	%edx, %eax
	movl	%eax, count.0(%rip)
	movl	count.0(%rip), %eax
	movl	%eax, -4(%rbp)
	movl	$0, count.0(%rip)
	movl	-4(%rbp), %eax
.L44:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	leaf, .-leaf
	.globl	max
	.bss
	.align 4
	.type	max, @object
	.size	max, 4
max:
	.zero	4
	.text
	.globl	finddia
	.type	finddia, @function
finddia:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L47
	movl	$0, %eax
	jmp	.L48
.L47:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	finddia
	movl	%eax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	finddia
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %eax
	leal	1(%rax), %edx
	movl	-4(%rbp), %eax
	addl	%eax, %edx
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	maximum
	movq	-32(%rbp), %rdx
	movl	%eax, (%rdx)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	maximum
	addl	$1, %eax
.L48:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	finddia, .-finddia
	.globl	successor
	.type	successor, @function
successor:
.LFB14:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L52
	movl	$0, %eax
	jmp	.L51
.L54:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -28(%rbp)
	jle	.L53
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L52
.L53:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -28(%rbp)
	jge	.L52
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L52:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -28(%rbp)
	jne	.L54
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L55
.L56:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L55
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
.L55:
	cmpq	$0, -24(%rbp)
	jne	.L56
	movl	-4(%rbp), %eax
.L51:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	successor, .-successor
	.globl	predecessor
	.type	predecessor, @function
predecessor:
.LFB15:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L60
	movl	$0, %eax
	jmp	.L59
.L63:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -28(%rbp)
	jle	.L61
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L60
.L61:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -28(%rbp)
	jge	.L60
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L60:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, -28(%rbp)
	je	.L62
	cmpq	$0, -24(%rbp)
	jne	.L63
.L62:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	jmp	.L64
.L65:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L64
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
.L64:
	cmpq	$0, -24(%rbp)
	jne	.L65
	movl	-4(%rbp), %eax
.L59:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	predecessor, .-predecessor
	.globl	atleastchild
	.type	atleastchild, @function
atleastchild:
.LFB16:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L67
	movl	$0, %eax
	jmp	.L68
.L67:
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L69
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L70
.L69:
	movl	$1, -4(%rbp)
.L70:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	atleastchild
	addl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	atleastchild
	addl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
.L68:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	atleastchild, .-atleastchild
	.globl	Height
	.type	Height, @function
Height:
.LFB17:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L72
	movl	$0, %eax
	jmp	.L73
.L72:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	Height
	movl	%eax, %ebx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	Height
	movl	%ebx, %esi
	movl	%eax, %edi
	call	maximum
	addl	$1, %eax
.L73:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	Height, .-Height
	.globl	case1
	.type	case1, @function
case1:
.LFB18:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-64(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -56(%rbp)
	jne	.L75
	movq	-8(%rbp), %rax
	movq	%rax, root(%rip)
	movq	-8(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	.L76
.L77:
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
.L76:
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L77
	movq	-40(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L78
.L75:
	movq	-8(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -64(%rbp)
	jne	.L79
	movq	-56(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L80
.L81:
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
.L80:
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L81
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L78
.L79:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, -64(%rbp)
	jne	.L78
	movq	-56(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L82
.L83:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L82:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L83
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L78:
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	case1, .-case1
	.globl	case2
	.type	case2, @function
case2:
.LFB19:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L85
	movq	root(%rip), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L85
	movq	root(%rip), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L86
	movq	root(%rip), %rax
	movq	8(%rax), %rax
	movq	%rax, root(%rip)
	jmp	.L92
.L86:
	movq	root(%rip), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L92
	movq	root(%rip), %rax
	movq	16(%rax), %rax
	movq	%rax, root(%rip)
	jmp	.L92
.L85:
	cmpq	$0, -8(%rbp)
	je	.L88
	cmpq	$0, -16(%rbp)
	je	.L88
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L89
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L90
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	jmp	.L88
.L90:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L88
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L88
.L89:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L88
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L91
	movq	-16(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	jmp	.L88
.L91:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L88
	movq	-16(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L88
.L92:
	nop
.L88:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	case2, .-case2
	.globl	case3
	.type	case3, @function
case3:
.LFB20:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L94
	movq	root(%rip), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L94
	movq	$0, root(%rip)
	jmp	.L95
.L94:
	cmpq	$0, -8(%rbp)
	je	.L95
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L96
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	jmp	.L95
.L96:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L95
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
.L95:
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE20:
	.size	case3, .-case3
	.section	.rodata
.LC3:
	.string	"ENter the item: "
.LC4:
	.string	"location found"
.LC5:
	.string	"no item to delte: "
	.text
	.globl	delete
	.type	delete, @function
delete:
.LFB21:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	searchloc
	movq	par(%rip), %rax
	testq	%rax, %rax
	jne	.L98
	movq	loc(%rip), %rax
	testq	%rax, %rax
	je	.L98
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L98:
	movq	par(%rip), %rax
	testq	%rax, %rax
	jne	.L99
	movq	loc(%rip), %rdx
	movq	root(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L99
	movq	root(%rip), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L100
	movq	root(%rip), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L100
	movq	loc(%rip), %rdx
	movq	par(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	case1
	jmp	.L101
.L100:
	movq	root(%rip), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L102
	movq	root(%rip), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L102
	movq	loc(%rip), %rdx
	movq	par(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	case3
	jmp	.L101
.L102:
	movq	loc(%rip), %rdx
	movq	par(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	case2
	jmp	.L97
.L101:
	jmp	.L97
.L99:
	movq	par(%rip), %rax
	testq	%rax, %rax
	jne	.L104
	movq	loc(%rip), %rax
	testq	%rax, %rax
	je	.L105
.L104:
	movq	par(%rip), %rax
	testq	%rax, %rax
	je	.L106
	movq	loc(%rip), %rax
	testq	%rax, %rax
	jne	.L106
.L105:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L97
.L106:
	movq	par(%rip), %rax
	testq	%rax, %rax
	je	.L97
	movq	par(%rip), %rax
	testq	%rax, %rax
	je	.L97
	movq	loc(%rip), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L108
	movq	loc(%rip), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L108
	movq	loc(%rip), %rdx
	movq	par(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	case3
	jmp	.L97
.L108:
	movq	loc(%rip), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L109
	movq	loc(%rip), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L109
	movq	loc(%rip), %rdx
	movq	par(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	case1
	jmp	.L97
.L109:
	movq	loc(%rip), %rdx
	movq	par(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	case2
.L97:
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L110
	call	__stack_chk_fail@PLT
.L110:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE21:
	.size	delete, .-delete
	.globl	arsize
	.bss
	.align 4
	.type	arsize, @object
	.size	arsize, 4
arsize:
	.zero	4
	.globl	arr
	.align 32
	.type	arr, @object
	.size	arr, 200
arr:
	.zero	200
	.text
	.globl	klargest
	.type	klargest, @function
klargest:
.LFB22:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L114
	movl	arsize(%rip), %edx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	arr(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	arsize(%rip), %eax
	addl	$1, %eax
	movl	%eax, arsize(%rip)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	klargest
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	klargest
	jmp	.L111
.L114:
	nop
.L111:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE22:
	.size	klargest, .-klargest
	.globl	rightcount
	.type	rightcount, @function
rightcount:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L116
	movl	$0, %eax
	jmp	.L117
.L116:
	movl	$1, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	rightcount
	addl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	rightcount
	addl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
.L117:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE23:
	.size	rightcount, .-rightcount
	.globl	leftcount
	.type	leftcount, @function
leftcount:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L119
	movl	$0, %eax
	jmp	.L120
.L119:
	movl	$1, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	leftcount
	addl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	leftcount
	addl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
.L120:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE24:
	.size	leftcount, .-leftcount
	.globl	atmost
	.type	atmost, @function
atmost:
.LFB25:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L122
	movl	$0, %eax
	jmp	.L123
.L122:
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	je	.L124
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L124
	movl	$1, -4(%rbp)
.L124:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	atmost
	addl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	atmost
	addl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
.L123:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE25:
	.size	atmost, .-atmost
	.section	.rodata
	.align 8
.LC6:
	.string	"\n\n1 - Insert element:\t\t\t2 - Preorder Traversal:"
	.align 8
.LC7:
	.string	"3 - Inorder Traversal:\t\t\t4 - Postorder Traversal:"
	.align 8
.LC8:
	.string	"5 - Deleting by element:\t\t6 - Search Element:"
	.align 8
.LC9:
	.string	"7 - Height of Tree:\t\t\t8 - Count of Leaf Nodes:"
	.align 8
.LC10:
	.string	"9 - K largest element:\t\t\t10 - count number of node with child:"
	.align 8
.LC11:
	.string	"11 - Number of leftnodes:\t\t12 - number of right nodes: "
	.align 8
.LC12:
	.string	"13 - Number of nodes with 2 child:\t14 - Diameter of tree:"
	.align 8
.LC13:
	.string	"15 - Successor of a number:\t\t16 - predecessor of a number:"
.LC14:
	.string	"\nEnter the choice: "
.LC15:
	.string	"Enter the item to search: "
.LC16:
	.string	"No element Found: "
	.align 8
.LC17:
	.string	"Element found at location : %p\n"
	.align 8
.LC18:
	.string	"The height of the tree is: %d\n"
.LC19:
	.string	"%d\n"
.LC20:
	.string	"Enter the n largest number: "
.LC21:
	.string	"The number is: %d"
	.align 8
.LC22:
	.string	"The number of nodes in the right subtree are: %d"
	.align 8
.LC23:
	.string	"The number of nodes on left subtree are: %d"
.LC24:
	.string	"The number of nodes: %d"
	.align 8
.LC25:
	.string	"Enter the element to find its successor: "
.LC26:
	.string	"The successor is: %d\n"
	.align 8
.LC27:
	.string	"Enter the element to find its predecessor: "
.LC28:
	.string	"The predecessor is: %d\n"
.LC29:
	.string	"Enter a valid choice:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB26:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$1, -69(%rbp)
	movl	$0, -44(%rbp)
	movl	$0, -40(%rbp)
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L126
.L156:
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-60(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-60(%rbp), %eax
	cmpl	$17, %eax
	ja	.L127
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L129(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L129(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L129:
	.long	.L127-.L129
	.long	.L145-.L129
	.long	.L144-.L129
	.long	.L143-.L129
	.long	.L142-.L129
	.long	.L141-.L129
	.long	.L140-.L129
	.long	.L139-.L129
	.long	.L138-.L129
	.long	.L137-.L129
	.long	.L136-.L129
	.long	.L135-.L129
	.long	.L134-.L129
	.long	.L133-.L129
	.long	.L132-.L129
	.long	.L131-.L129
	.long	.L130-.L129
	.long	.L128-.L129
	.text
.L145:
	movl	$0, %eax
	call	insert
	jmp	.L126
.L144:
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	preorder
	jmp	.L126
.L143:
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	inorder
	jmp	.L126
.L142:
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	postorder
	jmp	.L126
.L141:
	movl	$0, %eax
	call	delete
	jmp	.L126
.L140:
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-68(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-68(%rbp), %eax
	movl	%eax, %edi
	call	searchloc
	movq	loc(%rip), %rax
	testq	%rax, %rax
	jne	.L147
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L147:
	movq	loc(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L139:
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	Height
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC18(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L138:
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	leaf
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC19(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L137:
	movl	$0, arsize(%rip)
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	klargest
	movl	$0, -52(%rbp)
	jmp	.L149
.L153:
	movl	$0, -48(%rbp)
	jmp	.L150
.L152:
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	arr(%rip), %rax
	movl	(%rdx,%rax), %edx
	movl	-48(%rbp), %eax
	addl	$1, %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	arr(%rip), %rax
	movl	(%rcx,%rax), %eax
	cmpl	%eax, %edx
	jle	.L151
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	arr(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, -20(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	arr(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	-48(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	leaq	arr(%rip), %rdx
	movl	%eax, (%rcx,%rdx)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	arr(%rip), %rdx
	movl	-20(%rbp), %eax
	movl	%eax, (%rcx,%rdx)
.L151:
	addl	$1, -48(%rbp)
.L150:
	movl	arsize(%rip), %eax
	subl	$1, %eax
	subl	-52(%rbp), %eax
	cmpl	%eax, -48(%rbp)
	jl	.L152
	addl	$1, -52(%rbp)
.L149:
	movl	arsize(%rip), %eax
	cmpl	%eax, -52(%rbp)
	jl	.L153
	leaq	.LC20(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-64(%rbp), %eax
	subl	$1, %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	arr(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, %esi
	leaq	.LC21(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L136:
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	atleastchild
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L135:
	movq	root(%rip), %rax
	testq	%rax, %rax
	je	.L154
	movq	root(%rip), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	rightcount
	movl	%eax, -44(%rbp)
.L154:
	movl	-44(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC22(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L134:
	movq	root(%rip), %rax
	testq	%rax, %rax
	je	.L155
	movq	root(%rip), %rax
	movq	8(%rax), %rax
	movq	%rax, %rdi
	call	leftcount
	movl	%eax, -40(%rbp)
.L155:
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC23(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L133:
	movq	root(%rip), %rax
	movq	%rax, %rdi
	call	atmost
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L132:
	movl	$0, -56(%rbp)
	movq	root(%rip), %rax
	leaq	-56(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	finddia
	movl	-56(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L131:
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-68(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-68(%rbp), %edx
	movq	root(%rip), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	successor
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC26(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L130:
	leaq	.LC27(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-68(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-68(%rbp), %edx
	movq	root(%rip), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	predecessor
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC28(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L126
.L128:
	movb	$0, -69(%rbp)
	jmp	.L126
.L127:
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
.L126:
	cmpb	$0, -69(%rbp)
	jne	.L156
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L158
	call	__stack_chk_fail@PLT
.L158:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE26:
	.size	main, .-main
	.local	count.0
	.comm	count.0,4,4
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
