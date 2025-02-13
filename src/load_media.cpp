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
}