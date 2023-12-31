.set MAGICBR, 0x1badb002;
.set FLAGSBR, (1<<0 | 1<<1);
.set CHECKBR, -(MAGICBR + FLAGSBR);

.section .multibbot
	.long MAGICBR
	.long FLAGSBR
	.long CHECKBR

.section .text
.extern __Z9callCtorsv
.extern __Z10kernelMainPvj
.global loader

loader:
	mov $kernel_stack, %esp
	call __Z9callCtorsv
	push %eax
	push %ebx
	call __Z10kernelMainPvj

stop:
	cli	# 禁用中断
	hlt	# 使用hlt暂停cpu
	jmp stop	# 循环执行

.section .bss
.space 2 * 1024 * 1024
kernel_stack:

