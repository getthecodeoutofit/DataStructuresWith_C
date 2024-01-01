	.file	"Circular_LL.c"
	.text
	.globl	head
	.bss
	.align 8
	.type	head, @object
	.size	head, 8
head:
	.zero	8
	.section	.rodata
.LC0:
	.string	"Enter the element: "
.LC1:
	.string	"%d"
	.text
	.globl	Insert_front
	.type	Insert_front, @function
Insert_front:
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
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
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
	movl	-28(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movq	head(%rip), %rax
	testq	%rax, %rax
	jne	.L2
	movq	-16(%rbp), %rax
	movq	%rax, head(%rip)
	movq	head(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L6
.L2:
	movq	head(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	head(%rip), %rax
	movq	%rax, -24(%rbp)
.L4:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	head(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L4
	movq	-16(%rbp), %rax
	movq	%rax, head(%rip)
	movq	head(%rip), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
.L6:
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	Insert_front, .-Insert_front
	.section	.rodata
.LC2:
	.string	"Enter the item: "
	.text
	.globl	insert_back
	.type	insert_back, @function
insert_back:
.LFB7:
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
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	movq	head(%rip), %rax
	movq	%rax, -24(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-28(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movq	head(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	head(%rip), %rax
	testq	%rax, %rax
	jne	.L8
	movq	-16(%rbp), %rax
	movq	%rax, head(%rip)
	movq	head(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L11
.L8:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	head(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L8
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L11:
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	insert_back, .-insert_back
	.section	.rodata
	.align 8
.LC3:
	.string	"Enter the position you want to enter the element: "
	.text
	.globl	Insert_between
	.type	Insert_between, @function
Insert_between:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -16(%rbp)
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-36(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-36(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movq	head(%rip), %rax
	testq	%rax, %rax
	je	.L13
	movl	-32(%rbp), %eax
	cmpl	$1, %eax
	jne	.L14
.L13:
	movq	head(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	head(%rip), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, head(%rip)
	movq	head(%rip), %rax
	movq	%rax, -24(%rbp)
	jmp	.L15
.L14:
	movl	$1, -28(%rbp)
	jmp	.L16
.L18:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	addl	$1, -28(%rbp)
.L16:
	movl	-32(%rbp), %eax
	cmpl	%eax, -28(%rbp)
	jge	.L17
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	head(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L18
.L17:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
.L15:
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L19
	call	__stack_chk_fail@PLT
.L19:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	Insert_between, .-Insert_between
	.section	.rodata
.LC4:
	.string	"%d "
	.text
	.globl	display
	.type	display, @function
display:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	head(%rip), %rax
	movq	%rax, -8(%rbp)
.L21:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	head(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jne	.L21
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	display, .-display
	.section	.rodata
.LC5:
	.string	"No element to remove: "
	.text
	.globl	pop_front
	.type	pop_front, @function
pop_front:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	head(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	head(%rip), %rax
	testq	%rax, %rax
	jne	.L23
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L22
.L23:
	movq	head(%rip), %rax
	movq	%rax, -16(%rbp)
.L25:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	head(%rip), %rax
	cmpq	%rax, %rdx
	jne	.L25
	movq	head(%rip), %rax
	movq	8(%rax), %rax
	movq	%rax, head(%rip)
	movq	head(%rip), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
.L22:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	pop_front, .-pop_front
	.section	.rodata
.LC6:
	.string	"The node is empty: "
	.text
	.globl	pop_back
	.type	pop_back, @function
pop_back:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	head(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	head(%rip), %rax
	testq	%rax, %rax
	jne	.L26
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L26:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	pop_back, .-pop_back
	.section	.rodata
.LC7:
	.string	"No element to delete: "
	.align 8
.LC8:
	.string	"Enter the position to delete: "
.LC9:
	.string	"Range out of bound: "
	.text
	.globl	pop_between
	.type	pop_between, @function
pop_between:
.LFB12:
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
	movq	head(%rip), %rax
	testq	%rax, %rax
	jne	.L29
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L28
.L29:
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movq	head(%rip), %rax
	movq	%rax, -24(%rbp)
	movl	$1, -28(%rbp)
	jmp	.L31
.L32:
	addl	$1, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L31:
	movq	head(%rip), %rax
	cmpq	%rax, -24(%rbp)
	jne	.L32
	movq	head(%rip), %rax
	movq	%rax, -16(%rbp)
	movl	-32(%rbp), %eax
	cmpl	%eax, -28(%rbp)
	jl	.L33
	movl	-32(%rbp), %eax
	testl	%eax, %eax
	jle	.L33
	movl	-32(%rbp), %eax
	cmpl	$1, %eax
	jne	.L28
	movq	head(%rip), %rax
	movq	8(%rax), %rax
	movq	%rax, head(%rip)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	jmp	.L28
.L33:
	movl	-32(%rbp), %eax
	cmpl	%eax, -28(%rbp)
	jge	.L28
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L28:
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L37
	call	__stack_chk_fail@PLT
.L37:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	pop_between, .-pop_between
	.section	.rodata
	.align 8
.LC10:
	.string	"This is a circular linked list........................"
	.align 8
.LC11:
	.string	"1 - insertion front:\t\t2 - insertion between:"
	.align 8
.LC12:
	.string	"3 - insert at any location:\t4 - pop front:"
	.align 8
.LC13:
	.string	"4 - pop back:\t\t\t5 - pop from any location:"
	.align 8
.LC14:
	.string	"7 - Displayig the element:\t8 - Exiting the program:"
.LC15:
	.string	"Enter the choice: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
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
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movb	$1, -13(%rbp)
	nop
	jmp	.L40
.L50:
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC15(%rip), %rax
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
	cmpl	$8, %eax
	ja	.L40
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L42(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L42(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L42:
	.long	.L40-.L42
	.long	.L49-.L42
	.long	.L48-.L42
	.long	.L47-.L42
	.long	.L46-.L42
	.long	.L45-.L42
	.long	.L44-.L42
	.long	.L43-.L42
	.long	.L41-.L42
	.text
.L49:
	movl	$0, %eax
	call	Insert_front
	jmp	.L40
.L48:
	movl	$0, %eax
	call	insert_back
	jmp	.L40
.L47:
	movl	$0, %eax
	call	Insert_between
	jmp	.L40
.L46:
	movl	$0, %eax
	call	pop_front
	jmp	.L40
.L45:
	movl	$0, %eax
	call	pop_back
	jmp	.L40
.L44:
	movl	$0, %eax
	call	pop_between
	jmp	.L40
.L43:
	movl	$0, %eax
	call	display
	jmp	.L40
.L41:
	movb	$0, -13(%rbp)
	nop
.L40:
	cmpb	$0, -13(%rbp)
	jne	.L50
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L52
	call	__stack_chk_fail@PLT
.L52:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
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
