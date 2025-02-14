/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 15:56:19
 * @modify date 2025-02-13 15:56:19
 * @desc [description]
 */
#include "game.h"
#include "player.h"
#include "flake.h"

Game::~Game()
{
    this->flakes.clear();
    this->backgroud.reset();
    this->renderer.reset();
    this->window.reset();

    IMG_Quit();
    SDL_Quit();

    std::cout << "all clean!" << std::endl;
}
void Game::init()
{
    this->player.reset(new Player(this->renderer));
    this->player->init();

    for (int i = 0; i < 10; i++)
    {
        auto flake = std::make_unique<Flake>(this->renderer, this->white_image, this->white_rect, true, this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }

    for (int i = 0; i < 5; i++)
    {
        auto flake = std::make_unique<Flake>(this->renderer, this->yellow_image, this->yellow_rect, false, this->gen);
        flake->init();
        this->flakes.emplace_back(std::move(flake));
    }
}

void Game::events()
{
    while (SDL_PollEvent(&this->event))
    {
        switch (this->event.type)
        {
        case SDL_QUIT:
            this->running = false;
            return;
        case SDL_KEYDOWN:
            switch (this->event.key.keysym.scancode)
            {
            case SDL_SCANCODE_ESCAPE:
                this->running = false;
                return;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Game::update()
{
    player->update();
}

void Game::draw()
{
    SDL_RenderClear(this->renderer.get());

    SDL_RenderCopy(this->renderer.get(), this->backgroud.get(), nullptr, nullptr);

    this->player->draw();
    for (auto &falke : this->flakes)
    {
        falke->draw();
    }

    SDL_RenderPresent(this->renderer.get());
}

void Game::run()
{
    while (this->running)
    {
        this->events();

        this->update();

        this->draw();

        SDL_Delay(16);
    }
}
