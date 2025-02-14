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

  int height = is_full ? WINDOW_HEIGHT * 2 : WINDOW_HEIGHT;

  std::uniform_int_distribution<int> randX(0, (WINDOW_WIDTH - this->rect.w));

  std::uniform_int_distribution<int> randY(0, height);

  this->rect.x = randX(this->gen);

  this->rect.y = -randY(this->gen) - this->rect.h;
}

void Flake::update()
{
  this->rect.y += FLAKE_VEL;
  if (this->bottom() > GROUND)
  {
    this->reset(false);
  }
}
void Flake::draw() const
{
  SDL_RenderCopy(this->renderer.get(), this->image.get(), nullptr, &this->rect);
}