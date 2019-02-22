#pragma once
#include <stddef.h>
#include <stdint.h>

class TerminalContext
{
public:
    TerminalContext();

    void clear();

    void write_at(char c, size_t x, size_t y);
    void write(char c);
    void write(const char * data, size_t data_len);
    void write(const char * msg);

private:
    size_t _row;
    size_t _column;
    uint8_t _color;
    uint16_t * _buffer;
};