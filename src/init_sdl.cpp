/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 15:56:06
 * @modify date 2025-02-13 15:56:06
 * @desc [description]
 */
#include "init_sdl.h"

void Game::init_sdl()
{
    if (SDL_Init(SDL_FLAGS) != 0)
    {
        auto error = std::format("Error initializing SDL: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    if ((IMG_Init(IMG_FLAGS) & IMG_FLAGS) != IMG_FLAGS)
    {
        auto error = std::format("Error initializing SDL_image: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    this->window.reset(SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0));
    if (!this->window)
    {
        auto error = std::format("Error creating Window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->renderer.reset(SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED));
    if (!this->renderer)
    {
        auto error = std::format("Error creating Renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}