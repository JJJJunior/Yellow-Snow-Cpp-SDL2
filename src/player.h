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
<<<<<<< HEAD
          image{nullptr, SDL_DestroyTexture},
          rect{0, PLAYER_Y, 0, 0},
          keystate{nullptr},
          flip{SDL_FLIP_NONE},
          top_offset{16},
          left_offset{47},
          right_offset{43} {};
=======
          image{nullptr, SDL_DestroyTexture} {}
>>>>>>> d9bb957889ffef9c0355f1c72b35f31da79a7489

    void init();
    void update();
    void draw() const;

    inline int left() const
    {
        return this->rect.x + this->left_offset;
    }
    inline int right() const
    {
        return this->rect.x + this->rect.w - this->right_offset;
    }
    inline int top() const
    {
        return this->rect.y + this->top_offset;
    }
    inline void set_left()
    {
        this->rect.x = -this->left_offset;
    }
    inline void set_right()
    {
        this->rect.x = WINDOW_WIDTH - this->rect.w + this->right_offset;
    }

private:
    std::shared_ptr<SDL_Renderer> renderer;
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
    SDL_Rect rect;
    const Uint8 *keystate;
    SDL_RendererFlip flip;
    const int top_offset;
    const int left_offset;
    const int right_offset;
};

#endif