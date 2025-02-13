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
          image{nullptr, SDL_DestroyTexture} {}

    void init();
    void draw();

private:
    std::shared_ptr<SDL_Renderer> renderer;
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
    SDL_Rect rect;
};

#endif