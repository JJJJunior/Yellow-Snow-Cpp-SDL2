/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 22:00:22
 * @modify date 2025-02-13 22:00:22
 * @desc [description]
 */
#include "player.h"

Player::Player(std::shared_ptr<SDL_Renderer> renderer)
    : renderer{renderer},
      image{nullptr, SDL_DestroyTexture} {}

void Player::init()
{
    this->image.reset(IMG_LoadTexture(this->renderer.get(), "images/player.png"));
    if (!this->image)
    {
        auto error = std::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w, &this->rect.h) != 0)
    {
        auto error = std::format("Error querying Texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Player::draw()
{
    SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr, &this->rect);
}