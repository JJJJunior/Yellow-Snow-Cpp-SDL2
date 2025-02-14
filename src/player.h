/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 22:00:30
 * @modify date 2025-02-13 22:00:30
 * @desc [description]
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "main.h"

class Player
{
public:
    Player(std::shared_ptr<SDL_Renderer> new_renderer)
        : renderer{new_renderer},
          image{nullptr, SDL_DestroyTexture},
          rect{0, PLAYER_Y, 0, 0},
          keystate{nullptr},
          flip{SDL_FLIP_NONE} {};

    void init();
    void update();
    void draw() const;

    inline int left() const
    {
        return this->rect.x + PLAYER_LEFT_OFFSET;
    }
    inline int right() const
    {
        return this->rect.x + this->rect.w - PLAYER_RIGHT_OFFSET;
    }
    inline int top() const
    {
        return this->rect.y + PLAYER_TOP_OFFSET;
    }
    inline void set_left()
    {
        this->rect.x = -PLAYER_LEFT_OFFSET;
    }
    inline void set_right()
    {
        this->rect.x = WINDOW_WIDTH - this->rect.w + PLAYER_RIGHT_OFFSET;
    }

private:
    std::shared_ptr<SDL_Renderer> renderer;
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
    SDL_Rect rect;
    const Uint8 *keystate;
    SDL_RendererFlip flip;
};

#endif