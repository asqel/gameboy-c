#include "SDL.h"
#include "gameboy.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef NULL
#undef NULL
#define NULL ((char *)0)
#endif

bullshit_t random_bullshit = {0};


void SDL_Init(int x) {

}
void SDL_CreateWindowAndRenderer(int x, ...) {

}

void SDL_assert_func(int x, int line) {
	if (x)
		return ;
	fprintf(stderr, "ERROR SDL ASSERT FAILED %d", line);
	exit(1);
}

// if [0] == 0 it is 1 byte
//not in order
/*
0 - 9
A - B
*/
char scancodes[][2] = {
	{0, 0x0B}, // 0
	{0, 0x02}, // 1
	{0, 0x03}, // 2
	{0, 0x04}, // 3
	{0, 0x05}, // 4
	{0, 0x06}, // 5
	{0, 0x07}, // 6
	{0, 0x08}, // 7
	{0, 0x09}, // 8
	{0, 0x0A}, // 9
};

int SDL_PollEvent(SDL_Event *ev) {
	uint32_t key = c_kb_get_scfh();
	if (!key)
		return 0;
	if (0x02 <= key && key <= 0x0B) {
		ev->type = SDL_KEYDOWN;
		ev->key.keysym.sym = key - 0x02 + SDLK_1;
		return 1;
	}
	switch (key) {
		case 0x13:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_r;
			return 1;
		case 0x22:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_g;
			return 1;
		case 0x30:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_b;
			return 1;
		case 0x18:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_o;
			return 1;
		case 0x15:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_y;
			return 1;
		case 0x10:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_q;
			return 1;
		case 0x1D:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_LCTRL;
			return 1;
		case 0xE0:
			switch (c_kb_get_scfh()) {
				case 0x4D:
					ev->type = SDL_KEYDOWN;
					ev->key.keysym.sym = SDLK_RIGHT;
					return 1;
				case 0x4B:
					ev->type = SDL_KEYDOWN;
					ev->key.keysym.sym = SDLK_LEFT;
					return 1;
				case 0x48:
					ev->type = SDL_KEYDOWN;
					ev->key.keysym.sym = SDLK_UP;
					return 1;
				case 0x50:
					ev->type = SDL_KEYDOWN;
					ev->key.keysym.sym = SDLK_DOWN;
					return 1;
				case 0xC8:
					ev->type = SDL_KEYUP;
					ev->key.keysym.sym = SDLK_UP;
					return 1;
				case 0xD0:
					ev->type = SDL_KEYUP;
					ev->key.keysym.sym = SDLK_DOWN;
					return 1;
				case 0xCD:
					ev->type = SDL_KEYUP;
					ev->key.keysym.sym = SDLK_RIGHT;
					return 1;
				case 0xCB:
					ev->type = SDL_KEYUP;
					ev->key.keysym.sym = SDLK_LEFT;
					return 1;
			}
		case 0x2C:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_z;
			return 1;
		case 0x2D:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_x;
			return 1;
		case 0x36:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_RSHIFT;
			return 1;
		case 0x1C:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_RETURN;
			return 1;
		case 0x20:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_d;
			return 1;
		case 0x1E:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_a;
			return 1;
		case 0x11:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_w;
			return 1;
		case 0x1F:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_s;
			return 1;
		case 0x39:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_SPACE;
			return 1;
		case 0x0E:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_BACKSPACE;
			return 1;
		case 0x2A:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_LSHIFT;
			return 1;
		case 0x01:
			ev->type = SDL_KEYDOWN;
			ev->key.keysym.sym = SDLK_ESCAP;
			return 1;
		// key released
		case 0x90:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_q;
			return 1;
		case 0x9D:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_LCTRL;
			return 1;
		case 0x2C + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_z;
			return 1;
		case 0x2D + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_x;
			return 1;
		case 0x36 + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_RSHIFT;
			return 1;
		case 0x1C + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_RETURN;
			return 1;
		case 0x20 + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_d;
			return 1;
		case 0x1E + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_a;
			return 1;
		case 0x11 + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_w;
			return 1;
		case 0x1F + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_s;
			return 1;
		case 0x39 + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_SPACE;
			return 1;
		case 0x0E + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_BACKSPACE;
			return 1;
		case 0x2A + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_LSHIFT;
			return 1;
		case 0x01 + 0x80:
			ev->type = SDL_KEYUP;
			ev->key.keysym.sym = SDLK_ESCAP;
			return 1;
		default:
			ev->type = I_SDKL_NONE;
			ev->key.keysym.sym = I_SDKL_NONE;
			return 1;
	}
	return 0;
}

char *optarg = NULL;

#define getopt(...) i_replace_getopt(argc, argv, &rom_file)

int i_replace_getopt(int argc, char **argv, char **rom_file) {
	*rom_file = NULL;
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-f")) {
			i++;
			if (i >= argc) {
				printf("usage %s -f [rom file path]\n", argv[0]);
				exit(1);
			}
			*rom_file = argv[i];
		}
	}
	if (*rom_file == NULL) {
		printf("usage %s -f [rom file path]\n", argv[0]);
		exit(1);
	}
	return -1;
}

#define SIZE 3

void SDL_UpdateTexture(SDL_Texture *_, void *__, u32 img[LCD_HEIGHT][LCD_WIDTH], u32 ___) {
	uint32_t *fb = c_vesa_get_fb();
	uint32_t pitch = c_vesa_get_pitch();
	for (int x = 0; x < LCD_WIDTH; x++) {
		for (int y = 0; y < LCD_HEIGHT; y++) {
			for (int i = 0; i < SIZE; i++) {
				for (int k = 0; k < SIZE; k++) {
					fb[(x * SIZE + i) + (y * SIZE + k) *pitch] = img[y][x];
				}
			}
		}
	}
}