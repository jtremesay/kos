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

# Entry point of the kernel
.section .text
.global _start
.type _start, @function
_start:
    # Initialize the stack pointer
    mov $stack_top, %esp

    # Low-level initialization
    # TODO

    # Enter in the high-level part of the kernel
    call kernel_main

    # Halt
    cli
halt_loop:	hlt
	jmp halt_loop

.size _start, . - _start
