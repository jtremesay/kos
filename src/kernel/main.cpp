#include <stddef.h>
#include <stdint.h>

enum VGA_COLOR {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

class VGAConsole
{
public:
    VGAConsole(VGA_COLOR foreground_color=VGA_COLOR_WHITE, VGA_COLOR background_color=VGA_COLOR_BLUE) :
        _cursor_x(0),
        _cursor_y(0),
        _foreground_color(foreground_color),
        _background_color(background_color)
    {
        this->clear();
    }

    void clear()
    {
        const uint16_t vga_character = _background_color << 12 | _foreground_color << 8;
        for (size_t i = 0; i < _SCREEN_WIDTH * _SCREEN_HEIGHT; ++i) {
            _video_buffer[i] = vga_character;
        }
    }

    void write(const char * message)
    {
        for (; *message != 0; ++message) {
            this->write(*message);
        }
    }

    void write(char c)
    {
        if (c == '\t') {
            _cursor_x = 0;
        } else if (c == '\n') {
            _cursor_x = 0;
            if (++_cursor_y == _SCREEN_HEIGHT) {
                _cursor_y = 0;
            }
        } else {
            _video_buffer[_cursor_y * _SCREEN_WIDTH + _cursor_x] = _background_color << 12 | _foreground_color << 8 | c;
            if (++_cursor_x == _SCREEN_WIDTH) {
                _cursor_x = 0;
                if (++_cursor_y == _SCREEN_HEIGHT) {
                    _cursor_y = 0;
                }
            }
        }
    }

private:
    size_t _cursor_x;
    size_t _cursor_y;
    VGA_COLOR _foreground_color;
    VGA_COLOR _background_color;

    static uint16_t * _video_buffer;
    static const size_t _SCREEN_WIDTH;
    static const size_t _SCREEN_HEIGHT;
};

uint16_t * VGAConsole::_video_buffer = reinterpret_cast<uint16_t *>(0xB8000);
const size_t VGAConsole::_SCREEN_WIDTH = 80;
const size_t VGAConsole::_SCREEN_HEIGHT = 25;

extern "C" void kernel_main(void) 
{
    VGAConsole console;
    console.write("Hello, world\n");
    console.write("j'aime les pommes\n");
}