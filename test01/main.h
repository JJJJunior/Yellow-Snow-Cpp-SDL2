/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 15:55:55
 * @modify date 2025-02-13 15:55:55
 * @desc [description]
 */
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <format>
#include <memory>
#include <random>

constexpr Uint32 SDL_FLAGS = SDL_INIT_EVERYTHING;
constexpr int IMG_FLAGS = IMG_INIT_PNG;

constexpr char WINDOW_TITLE[] = "Don't Eat the Yellow Snow!";
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

constexpr int PLAYER_Y = 376;
constexpr int PLAYER_LEFT_OFFSET = 45;
constexpr int PLAYER_RIGHT_OFFSET = 45;
constexpr int PLAYER_TOP_OFFSET = 16;

constexpr int PLAYER_VEL = 5;
constexpr int GROUND = 550;
constexpr int FLAKE_VEL = 5;

#endif