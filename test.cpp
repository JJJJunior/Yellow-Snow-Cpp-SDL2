/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-14 16:38:28
 * @modify date 2025-02-14 16:38:28
 * @desc [description]
 */
#include <iostream>
#include <SDL2/SDL.h>
#include <memory>
#include <format>

constexpr Uint32 SDL_FLAGES = SDL_INIT_EVERYTHING;
constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;
constexpr char WINDOW_TITLE[] = "Open Window";

class Game
{
public:
    Game() : window{nullptr, SDL_DestroyWindow}, renderer{nullptr, SDL_DestroyRenderer} {};
    ~Game();

    void init_sdl();
    void run();

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
    std::shared_ptr<SDL_Renderer> renderer;
};

void Game::init_sdl()
{
    if (SDL_Init(SDL_FLAGES) != 0)
    {
        auto error = std::format("Error initializing SDL: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->window.reset(SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0));
    if (!this->window)
    {
        auto error = std::format("Error creating window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->renderer.reset(SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer);
    if (!this->renderer)
    {
        auto error = std::format("Error creating renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

Game::~Game()
{
    this->renderer.reset();
    this->window.reset();
    SDL_Quit();
}

void Game::run()
{
    SDL_RenderClear(this->renderer.get());
    SDL_RenderPresent(this->renderer.get());
    SDL_Delay(2000);
}

int main(void)
{
    try
    {
        Game game;
        game.init_sdl();
        game.run();
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}