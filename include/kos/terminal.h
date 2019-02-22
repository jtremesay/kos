#pragma once
#include <stddef.h>
#include <stdint.h>

/**
 * Context of a terminal
 */
class TerminalContext
{
public:
    /**
     * Initialize the context
     */
    TerminalContext();

    /**
     * Clear the screen
     */
    void clear();

    /**
     * Write a character at the specified position
     * @param c The character to write
     * @param x X coordinate
     * @param y Y coordinate
     */
    void write_at(char c, size_t x, size_t y);

    /**
     * Write a character
     */
    void write(char c);

    /**
     * Write a data buffer
     * @param data The buffer
     * @param data_len The length of the buffer
     */
    void write(const char * data, size_t data_len);

    /**
     * Write a string
     * @param msg The string
     */
    void write(const char * msg);

private:
    /**
     * X coordinate of the curson
     */
    size_t _column;

    /**
     * Y coordinate of the cursor
     */
    size_t _row;

    /**
     * Current color
     */
    uint8_t _color;

    /**
     * Address of the video buffer
     */
    uint16_t * _buffer;
};