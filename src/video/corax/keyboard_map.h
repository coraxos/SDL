#pragma once

#include "assert.h"

#define KEYBOARD_DEVICE "/dev/keyboard"
#define SCANCODE_KEY_RELEASED 0x80

typedef unsigned char uint8_t;
extern uint8_t scancode_to_key[120];

typedef enum {
	KEY_ESCAPE = 0x1,
	KEY_ONE = 0x2,
	KEY_TWO = 0x3,
	KEY_THREE = 0x4,
	KEY_FOUR = 0x5,
	KEY_FIVE = 0x6,
	KEY_SIX = 0x7,
	KEY_SEVEN = 0x8,
	KEY_EIGHT = 0x9,
	KEY_NINE = 0xa,
	KEY_ZERO = 0xb,
	KEY_MINUS = 0xc,
	KEY_EQUAL = 0xd,
	KEY_DELETE = 0xe,
	KEY_TAB = 0xf,
	KEY_Q = 0x10,
	KEY_W = 0x11,
	KEY_E = 0x12,
	KEY_R = 0x13,
	KEY_T = 0x14,
	KEY_Y = 0x15,
	KEY_U = 0x16,
	KEY_I = 0x17,
	KEY_O = 0x18,
	KEY_P = 0x19,
	KEY_BRACKETLEFT = 0x1a,
	KEY_BRACKETRIGHT = 0x1b,
	KEY_RETURN = 0x1c,
	KEY_CONTROL_1 = 0x1d,
	KEY_A = 0x1e,
	KEY_S = 0x1f,
	KEY_D = 0x20,
	KEY_F = 0x21,
	KEY_G = 0x22,
	KEY_H = 0x23,
	KEY_J = 0x24,
	KEY_K = 0x25,
	KEY_L = 0x26,
	KEY_SEMICOLON = 0x27,
	KEY_APOSTROPHE = 0x28,
	KEY_GRAVE = 0x29,
	KEY_SHIFT_1 = 0x2A,
	KEY_BACKSLASH = 0x2B,
	KEY_Z = 0x2C,
	KEY_X = 0x2D,
	KEY_C = 0x2E,
	KEY_V = 0x2F,
	KEY_B = 0x30,
	KEY_N = 0x31,
	KEY_M = 0x32,
	KEY_COMMA = 0x33,
	KEY_PERIOD = 0x34,
	KEY_SLASH = 0x35,
	KEY_SHIFT_2 = 0x36,
	KEY_KP_MULTIPLY = 0x37,
	KEY_ALT = 0x38,
	KEY_SPACE = 0x39,
	KEY_CAPS_LOCK = 0x3A,
	KEY_F1 = 0x3B,
	KEY_F2 = 0x3C,
	KEY_F3 = 0x3D,
	KEY_F4 = 0x3E,
	KEY_F5 = 0x3F,
	KEY_F6 = 0x40,
	KEY_F7 = 0x41,
	KEY_F8 = 0x42,
	KEY_F9 = 0x43,
	KEY_F10 = 0x44,
	KEY_NUM_LOCK = 0x45,
	KEY_SCROLL_LOCK = 0x46,
	KEY_KP_7 = 0x47,
	KEY_KP_8 = 0x48,
	KEY_KP_9 = 0x49,
	KEY_KP_SUBTRACT = 0x4A,
	KEY_KP_4 = 0x4B,
	KEY_KP_5 = 0x4C,
	KEY_KP_6 = 0x4D,
	KEY_KP_ADD = 0x4E,
	KEY_KP_1 = 0x4F,
	KEY_KP_2 = 0x50,
	KEY_KP_3 = 0x51,
	KEY_KP_0 = 0x52,
	KEY_KP_PERIOD = 0x53,
	KEY_LAST_CONSOLE = 0x54,
	KEY_LESS = 0x56,
	KEY_F11 = 0x57,
	KEY_F12 = 0x58,
	KEY_KP_ENTER = 0x60,
	KEY_CONTROL_2 = 0x61,
	KEY_KP_DIVIDE = 0x62,
	KEY_COMPOSE = 0x63,
	KEY_ALTGR = 0x64,
	KEY_BREAK = 0x65,
	KEY_FIND = 0x66,
	KEY_UP = 0x67,
	KEY_PRIOR = 0x68,
	KEY_LEFT = 0x69,
	KEY_RIGHT = 0x6A,
	KEY_SELECT = 0x6B,
	KEY_DOWN = 0x6C,
	KEY_NEXT = 0x6D,
	KEY_INSERT = 0x6E,
	KEY_REMOVE = 0x6F,
	KEY_MACRO = 0x70,
	KEY_F13 = 0x71,
	KEY_F14 = 0x72,
	KEY_HELP = 0x73,
	KEY_DO = 0x74,
	KEY_F17 = 0x75,
	KEY_KP_MINPLUS = 0x76,
	KEY_PAUSE = 0x77,

	//ALiases
	KEY_KP_UP = KEY_KP_8,
	KEY_KP_DOWN = KEY_KP_2,
	KEY_KP_LEFT = KEY_KP_4,
	KEY_KP_RIGHT = KEY_KP_6,
} keyboard_key_t;

static inline int isKeyPressed(uint8_t scancode)
{
	return (scancode & SCANCODE_KEY_RELEASED) == 0;
}
static inline uint8_t getKey(uint8_t scancode)
{
	assert(scancode_to_key[0] ==
	       0x1); //Make sure scancode table is initialized
	return scancode_to_key[scancode];
}
static inline uint8_t getScancode(uint8_t raw_scancode)
{
	return raw_scancode & ~SCANCODE_KEY_RELEASED;
}
static inline void initialize_scancode_table()
{
	scancode_to_key[0] = 0x1;
	scancode_to_key[KEY_ONE] = '1';
	scancode_to_key[KEY_TWO] = '2';
	scancode_to_key[KEY_THREE] = '3';
	scancode_to_key[KEY_FOUR] = '4';
	scancode_to_key[KEY_FIVE] = '5';
	scancode_to_key[KEY_SIX] = '6';
	scancode_to_key[KEY_SEVEN] = '7';
	scancode_to_key[KEY_EIGHT] = '8';
	scancode_to_key[KEY_NINE] = '9';

	scancode_to_key[KEY_Q] = 'q';
	scancode_to_key[KEY_W] = 'w';
	scancode_to_key[KEY_E] = 'e';
	scancode_to_key[KEY_R] = 'r';
	scancode_to_key[KEY_T] = 't';
	scancode_to_key[KEY_Y] = 'y';
	scancode_to_key[KEY_U] = 'u';
	scancode_to_key[KEY_I] = 'i';
	scancode_to_key[KEY_O] = 'o';
	scancode_to_key[KEY_P] = 'p';
	scancode_to_key[KEY_A] = 'a';
	scancode_to_key[KEY_S] = 's';
	scancode_to_key[KEY_D] = 'd';
	scancode_to_key[KEY_F] = 'f';
	scancode_to_key[KEY_G] = 'g';
	scancode_to_key[KEY_H] = 'h';
	scancode_to_key[KEY_J] = 'j';
	scancode_to_key[KEY_K] = 'k';
	scancode_to_key[KEY_L] = 'l';
	scancode_to_key[KEY_Z] = 'z';
	scancode_to_key[KEY_X] = 'x';
	scancode_to_key[KEY_C] = 'c';
	scancode_to_key[KEY_V] = 'v';
	scancode_to_key[KEY_B] = 'b';
	scancode_to_key[KEY_N] = 'n';
	scancode_to_key[KEY_M] = 'm';

	scancode_to_key[KEY_RETURN] = '\n';
	scancode_to_key[KEY_SLASH] = '/';
	scancode_to_key[KEY_BACKSLASH] = '\\';
	scancode_to_key[KEY_DELETE] = '\b';
	scancode_to_key[KEY_SPACE] = ' ';
}