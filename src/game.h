/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 15:56:10
 * @modify date 2025-02-13 15:56:10
 * @desc [description]
 */
#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "player.h"

class Game
{
public:
    Game()
        : window{nullptr, SDL_DestroyWindow},
          renderer{nullptr, SDL_DestroyRenderer},
          event{},
          running{true},
          backgroud{nullptr, SDL_DestroyTexture},
          player{nullptr} {};

    ~Game();

    void init_sdl();
    void load_media();
    void init();
    void run();

private:
    void events();
    void draw();

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
    std::shared_ptr<SDL_Renderer> renderer;
    SDL_Event event;
    bool running;
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> backgroud;
    std::unique_ptr<Player> player;
};

#endif