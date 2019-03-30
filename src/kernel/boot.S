#define ASM_FILE
#include <kernel/boot/multiboot2.h>

// Declare multiboot entry
.section .multiboot2_header
.align 8
multiboot2_header_begin:
    // Multiboot2: header
    .long MULTIBOOT2_HEADER_MAGIC // Magic number
    .long MULTIBOOT2_HEADER_ARCHITECTURE // Architecture
    .long multiboot2_header_end - multiboot2_header_begin // Size
    .long -(MULTIBOOT2_HEADER_MAGIC + MULTIBOOT2_HEADER_ARCHITECTURE + (multiboot2_header_end - multiboot2_header_begin)) // Checksum

/*
    // Multiboot2: tag adress
multiboot2_tag_address_start:
    .short MULTIBOOT2_TAG_TYPE_ADDRESS // Type
    .short MULTIBOOT2_TAG_FLAG_TAG_OPTIONAL // Flags
    .long multiboot2_tag_address_end - multiboot2_tag_address_start // Size
    .long multiboot2_header_begin // Begin of Multiboot2 header 
    .long start_begin // Begin of _start
    .long start_end // End of _start
    .long stack_top // BSS end
*/

multiboot2_tag_address_end:
    // Multiboot2: end tag
    .short MULTIBOOT2_TAG_TYPE_END_OF_TAG
    .short 0
    .long 8
multiboot2_header_end:

// Create the kernel stack
#define STACK_SIZE 0x4000
.section .bss
.align 16
stack_bottom:
.skip STACK_SIZE
stack_top:

.section .text
.align 4
.global _start
.type _start, @function
_start:
start_begin:
    
    // Initialize the stack pointer
    mov $stack_top, %esp

    call kernel_main

    // Halt
    cli
halt_loop:	hlt
	jmp halt_loop
start_end:
.size start_end, start_end - start_begin
