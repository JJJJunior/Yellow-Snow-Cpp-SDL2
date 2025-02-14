/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-14 19:48:33
 * @modify date 2025-02-14 19:48:33
 * @desc [description]
 */
#ifndef FLAKE_H
#define FLAKE_H
#include "main.h"

class Flake
{
public:
  Flake(std::shared_ptr<SDL_Renderer> renderer,
        std::shared_ptr<SDL_Texture> image,
        SDL_Rect rect,
        bool is_white,
        std::mt19937 &gen)
      : renderer{renderer},
        image{image},
        rect{rect},
        is_white{is_white},
        gen{gen} {};

  void reset(bool is_full);
  inline void init()
  {
    this->reset(true);
  }
  void update();
  void draw() const;

  inline int left() const
  {
    return this->rect.x;
  }
  inline int right() const
  {
    return this->rect.y + this->rect.w;
  }
  inline int bottom() const
  {
    return this->rect.y + this->rect.h;
  }
  inline bool isWhite() const
  {
    return this->is_white;
  }

private:
  std::shared_ptr<SDL_Renderer> renderer;
  std::shared_ptr<SDL_Texture> image;
  SDL_Rect rect;
  bool is_white;
  std::mt19937 &gen;
};
#endif