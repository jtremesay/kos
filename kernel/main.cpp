#include <kos/terminal.h>

extern "C" void kernel_main(void) 
{
    // Initialize the terminal context
    TerminalContext terminal_ctx;

    // Write boot stuff to the terminal
    terminal_ctx.write("kOS (killruana's Operating System) v0.0.1\n");
    terminal_ctx.write("Copyright 2019, killruana <killruana@slaanesh.org>\n");

    // Initialize the system
    terminal_ctx.write("\nBooting...\n");
    // TODO
    terminal_ctx.write("System initialized.\n\n");

    // Running
    // TODO

    // End of execution
    terminal_ctx.write("Power off...\n");
    // TODO
    terminal_ctx.write("System halted.\n");
}