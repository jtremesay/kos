#pragma once
#include <stddef.h>
#include <stdint.h>

/**
 * Width of the VGA screen
 */
extern const size_t VGA_WIDTH;

/**
 * Height of the VGA screen
 */
extern const size_t VGA_HEIGHT;

/**
 * Palette of VGA colors
 */
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

uint8_t vga_entry_color(VGA_COLOR fg, VGA_COLOR bg);
uint16_t vga_entry(unsigned char uc, uint8_t color) ;