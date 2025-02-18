/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 18:49:41
 * @modify date 2025-02-13 18:49:41
 * @desc [description]
 */
#include "load_media.h"

void Game::load_media()
{
    this->backgroud.reset(IMG_LoadTexture(this->renderer.get(), "images/background.png"));
    if (!this->backgroud)
    {
        auto error = std::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    this->white_image.reset(IMG_LoadTexture(this->renderer.get(), "images/white.png"), SDL_DestroyTexture);
    if (!this->white_image)
    {
        auto error = std::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->white_image.get(), nullptr, nullptr, &this->white_rect.w, &this->white_rect.h))
    {
        auto error = std::format("Error querying Texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->yellow_image.reset(IMG_LoadTexture(this->renderer.get(), "images/yellow.png"), SDL_DestroyTexture);
    if (!this->yellow_image)
    {
        auto error = std::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->yellow_image.get(), nullptr, nullptr, &this->yellow_rect.w, &this->yellow_rect.h))
    {
        auto error = std::format("Error querying Texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}