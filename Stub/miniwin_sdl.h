#pragma once

#include <assert.h>
#include <deque>
#include <dirent.h>
#include <functional>
#include <iostream>
#include <memory>
#include <queue>
#include <set>
#include <map>
#include <stdarg.h>
#include <string>
#include <utility>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_thread.h>
#include <SDL_ttf.h>

typedef SDL_mutex *CRITICAL_SECTION, **LPCRITICAL_SECTION;
VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

#define SDL_CHECK(e) assert(e == 0)

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;
extern SDL_Surface *surface;
extern SDL_Palette *palette;
extern SDL_Surface *pal_surface;

void sdl_present_surface();

#ifdef __WINDOWS__
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

void sdl_update_entire_surface();