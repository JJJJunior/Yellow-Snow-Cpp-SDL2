/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-14 20:20:32
 * @modify date 2025-02-14 20:20:32
 * @desc [description]
 */
#include "flake.h"

void Flake::reset(bool is_full)
{
  (void)is_full;

  std::uniform_int_distribution<int> randx(0, (WINDOW_WIDTH - this->rect.w));

  std::uniform_int_distribution<int> randy(0, (WINDOW_HEIGHT - this->rect.h));

  this->rect.x = randx(this->gen);

  this->rect.y = randy(this->gen);
}

void Flake::draw()
{
  SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr, &this->rect);
}