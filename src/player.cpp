/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 22:00:22
 * @modify date 2025-02-13 22:00:22
 * @desc [description]
 */
#include "player.h"

<<<<<<< HEAD
=======
Player::Player(std::shared_ptr<SDL_Renderer> renderer)
    : renderer{nullptr},
      image{nullptr, SDL_DestroyTexture} {}

>>>>>>> d9bb957889ffef9c0355f1c72b35f31da79a7489
void Player::init()
{
    this->image.reset(IMG_LoadTexture(this->renderer.get(), "images/player.png"));
    if (!this->image)
    {
        auto error = std::format("Error loading Texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (SDL_QueryTexture(this->image.get(), nullptr, nullptr, &this->rect.w, &this->rect.h))
    {
        auto error = std::format("Error querying Texture: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->rect.x = (WINDOW_WIDTH - this->rect.w) / 2;
    this->keystate = SDL_GetKeyboardState(nullptr);
}

void Player::update()
{
    if (this->keystate[SDL_SCANCODE_LEFT])
    {
        this->rect.x -= PLAYER_SPEED;
        if (this->left() < 0)
        {
            this->set_left();
        }
        this->flip = SDL_FLIP_HORIZONTAL;
    }
    if (this->keystate[SDL_SCANCODE_RIGHT])
    {
        this->rect.x += PLAYER_SPEED;
        if (this->right() > WINDOW_WIDTH)
        {
            this->set_right();
        }
        this->flip = SDL_FLIP_NONE;
    }
}

void Player::draw() const
{
    SDL_RenderCopyEx(this->renderer.get(), this->image.get(), nullptr, &this->rect, 0, nullptr, this->flip);
}