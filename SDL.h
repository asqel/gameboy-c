#ifndef SDL_H
#define SDL_H

#include <profan/syscall.h>
#include <unistd.h>
#include "gameboy.h"

typedef struct {
	int sym;
} i_keysym_t;

typedef struct {
	i_keysym_t keysym;
} i_key_t;



typedef struct {
	int type;
	i_key_t key;
} SDL_Event;

enum SDLK_keys_n_event {
	I_SDKL_NONE,
	SDLK_RIGHT,
	SDLK_LEFT,
	SDLK_UP,
	SDLK_DOWN,
	SDLK_z,
	SDLK_x,
	SDLK_RSHIFT,
	SDLK_RETURN,
	SDLK_d,
	SDLK_a,
	SDLK_w,
	SDLK_s,
	SDLK_SPACE,
	SDLK_BACKSPACE,
	SDLK_LSHIFT,
	SDLK_ESCAP,
	SDLK_ESCAPE,
	SDL_QUIT,
	SDL_KEYDOWN,
	SDLK_1,
	SDLK_2,
	SDLK_3,
	SDLK_4,
	SDLK_5,
	SDLK_6,
	SDLK_7,
	SDLK_8,
	SDLK_9,
	SDLK_0,
	SDLK_r,
	SDLK_g,
	SDLK_b,
	SDLK_o,
	SDLK_y,
	SDLK_q,
	SDLK_LCTRL,
	SDL_KEYUP
};

typedef struct {
	char x;
} bullshit_t;

typedef bullshit_t SDL_Window;
typedef bullshit_t SDL_Renderer;
typedef bullshit_t SDL_Texture;

#define SDL_INIT_VIDEO 0

void SDL_Init(int x);

void SDL_CreateWindowAndRenderer(int x, ...);

//#define SDL_assert(X) SDL_assert_func(X, __LINE__);
#define SDL_assert(...) ;
void SDL_assert_func(int x, int len);
#define SDL_WINDOW_RESIZABLE 0
#define SDL_PIXELFORMAT_RGBA32 0
#define SDL_TEXTUREACCESS_STREAMING 0

#define SDL_GetTicks c_timer_get_ms

extern char *optarg;

extern bullshit_t random_bullshit;

#define SDL_CreateTexture(...) (&(bullshit_t){.x = 0})
void SDL_UpdateTexture(SDL_Texture *, void *, uint32_t img[LCD_HEIGHT][LCD_WIDTH], u32 ___);

int SDL_PollEvent(SDL_Event *ev);

#define SDL_RenderClear(...) ((void)0)
#define SDL_RenderCopy(...) ((void)0)
#define SDL_RenderPresent(...) ((void)0)

#define SDL_SetWindowTitle(...) ((void)0)

#define SDL_Delay(X) usleep((X)*1000)

#define SDL_Quit() ;

#define rewind(X) fseek(X, 0, SEEK_SET)

#define getopt(...) i_replace_getopt(argc, argv, &rom_file)

int i_replace_getopt(int argc, char **argv, char **rom_file);

#endif