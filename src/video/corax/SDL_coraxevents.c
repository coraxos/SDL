/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2012 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/
#include "SDL_config.h"

/* Being a null driver, there's no event stream. We just define stubs for
   most of the API. */

#include "SDL.h"
#include "../../events/SDL_sysevents.h"
#include "../../events/SDL_events_c.h"

#include "SDL_coraxvideo.h"
#include "SDL_coraxevents_c.h"

#include "keyboard_map.h"


#define F_SETFL 0
#define O_NONBLOCK 1

unsigned char scancode_to_key[120];

void CORAX_InitOSKeymap(_THIS)
{
    initialize_scancode_table();
    //Make stdin non blocking
    fcntl(0, F_SETFL, O_NONBLOCK);
}

SDLKey getSDLSym(uint8_t character)
{
    switch (character)
    {
        case KEY_RETURN:
            return SDLK_RETURN;
        case KEY_SPACE:
            return SDLK_SPACE;
        case KEY_DELETE:
            return SDLK_BACKSPACE;
        case KEY_ESCAPE:
            return SDLK_ESCAPE;
        case KEY_KP_4:
        case KEY_LEFT:
            return SDLK_LEFT;
        case KEY_KP_6:
        case KEY_RIGHT:
            return SDLK_RIGHT;
        case KEY_KP_8:
        case KEY_UP:
            return SDLK_UP;
        case KEY_KP_2:
        case KEY_DOWN:
            return SDLK_DOWN;
        case KEY_CONTROL_1:
            return SDLK_LCTRL;
        case KEY_CONTROL_2:
            return SDLK_RCTRL;
        case KEY_SHIFT_1:
            return SDLK_LSHIFT;
        case KEY_SHIFT_2:
            return SDLK_RSHIFT;
        case KEY_TAB:
            return SDLK_TAB;
        case KEY_SLASH:
            return SDLK_SLASH;
        case KEY_ALT:
            return SDLK_LALT;
        case KEY_CAPS_LOCK:
            return SDLK_CAPSLOCK;
        case KEY_BRACKETLEFT:
            return SDLK_LEFTBRACKET;
        case KEY_BRACKETRIGHT:
            return SDLK_RIGHTBRACKET;
        case KEY_F1:
            return SDLK_F1;
        case KEY_F2:
            return SDLK_F2;
        case KEY_F3:
            return SDLK_F3;
        case KEY_F4:
            return SDLK_F4;
        case KEY_F5:
            return SDLK_F5;
        case KEY_F6:
            return SDLK_F6;
        case KEY_F7:
            return SDLK_F7;
        case KEY_F8:
            return SDLK_F8;
        case KEY_F9:
            return SDLK_F9;
        case KEY_F10:
            return SDLK_F10;
        case KEY_F11:
            return SDLK_F11;
        case KEY_F12:
            return SDLK_F12;
        case KEY_INSERT:
            return SDLK_INSERT;
        case KEY_A: return SDLK_a;
        case KEY_B: return SDLK_b;
        case KEY_C: return SDLK_c;
        case KEY_D: return SDLK_d;
        case KEY_E: return SDLK_e;
        case KEY_F: return SDLK_f;
        case KEY_G: return SDLK_g;
        case KEY_H: return SDLK_h;
        case KEY_I: return SDLK_i;
        case KEY_J: return SDLK_j;
        case KEY_K: return SDLK_k;
        case KEY_L: return SDLK_l;
        case KEY_M: return SDLK_m;
        case KEY_N: return SDLK_n;
        case KEY_O: return SDLK_o;
        case KEY_P: return SDLK_p;
        case KEY_Q: return SDLK_q;
        case KEY_R: return SDLK_r;
        case KEY_S: return SDLK_s;
        case KEY_T: return SDLK_t;
        case KEY_U: return SDLK_u;
        case KEY_V: return SDLK_v;
        case KEY_W: return SDLK_w;
        case KEY_X: return SDLK_x;
        case KEY_Y: return SDLK_y;
        case KEY_Z: return SDLK_z;
        case KEY_ONE: return SDLK_1;
        case KEY_TWO: return SDLK_2;
        case KEY_THREE: return SDLK_3;
        case KEY_FOUR: return SDLK_4;
        case KEY_FIVE: return SDLK_5;
        case KEY_SIX: return SDLK_6;
        case KEY_SEVEN: return SDLK_7;
        case KEY_EIGHT: return SDLK_8;
        case KEY_NINE: return SDLK_9;
        case KEY_ZERO: return SDLK_0;
    default:
        return SDLK_UNKNOWN;
    }
}

void CORAX_PumpEvents(_THIS)
{
    int raw_scancode = getc(stdin);
    while (raw_scancode != EOF)
    {
        if(raw_scancode == 0) {
            continue;
        }
        uint8_t scancode = getScancode(raw_scancode);
        int action = isKeyPressed(raw_scancode) ? SDL_PRESSED : SDL_RELEASED;

        SDL_keysym keysym;
        keysym.sym = getSDLSym(scancode);
        SDL_PrivateKeyboard(action, &keysym);

        raw_scancode = getc(stdin);
    }
}