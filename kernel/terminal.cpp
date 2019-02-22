#include <kos/terminal.h>
#include <kos/string.h>
#include <kos/vga.h>

TerminalContext::TerminalContext() :
    _row(0),
    _column(0),
    _color(vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK)),
    _buffer(reinterpret_cast<uint16_t *>(0xB8000)) // Address of the VGA buffer
{
    this->clear();
}

void TerminalContext::clear()
{
    for (size_t y = 0; y < VGA_HEIGHT; ++y) {
        for (size_t x = 0; x < VGA_WIDTH; ++x) {
            const size_t index = y * VGA_WIDTH + x;
            _buffer[index] = vga_entry(' ', _color);
        }
    }
}

void TerminalContext::write_at(char c, size_t x, size_t y)
{
    const size_t index = y * VGA_WIDTH + x;
    _buffer[index] = vga_entry(c, _color);
}

void TerminalContext::write(char c)
{
    if (c == '\n') {
        _column = 0;
        if (++_row == VGA_HEIGHT) {
            _row = 0;
        }
    } else if (c == '\r') {
        _column = 0;
    } else {
        this->write_at(c, _column, _row);
        if (++_column == VGA_WIDTH) {
            _column = 0;
            if (++_row == VGA_HEIGHT) {
                _row = 0;
            }
        }
    }
}

void TerminalContext::write(const char * data, size_t data_len)
{
    for (size_t i = 0; i < data_len; ++i) {
        this->write(data[i]);
    }
}

void TerminalContext::write(const char * msg)
{
    const size_t msg_len = get_length(msg);
    this->write(msg, msg_len);
}