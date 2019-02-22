#include <kos/terminal.h>

extern "C" void kernel_main(void) 
{
    // Initialize the Terminal context
    TerminalContext terminal_ctx;

    // Write Some stuff to the terminal
    terminal_ctx.write("kOS (killruana's Operating System) v0.0.1\n");
    terminal_ctx.write("Copyright 2019, killruana <killruana@slaanesh.org>\n");

    // Running
    // TODO

    // End of execution
    terminal_ctx.write("Halt.\n");
}