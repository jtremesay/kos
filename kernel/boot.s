# Declare constants for the multiboot header
.set ALIGN,    1 << 0           # Align loaded module on page boundaries
.set MEM_INFO, 1 << 1           # Provide memory map
.set FLAGS,    ALIGN | MEM_INFO # Multiboot "flag" field
.set MAGIC,    0x1BADB002       # Magic number
.set CHECKSUM, -(MAGIC + FLAGS) # Checksum of above

# Declare the multiboot header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Allocate a 16 kiB stack for the kernel
.section .bss
.align 16
stack_bottom:
.skip 16384 # 16 kiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:
    mov $stack_top, %esp

    call kernel_main

    cli
1:	hlt
	jmp 1b

.size _start, . - _start
