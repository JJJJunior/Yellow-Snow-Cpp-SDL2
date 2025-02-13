/**
 * @author junexiang
 * @email xj.master@mail.com
 * @create date 2025-02-13 15:55:03
 * @modify date 2025-02-13 15:55:03
 * @desc [description]
 */

#include "game.h"

int main(int argc, char *argv[])
{
    try
    {
        Game game;
        game.init_sdl();
        game.load_media();
        game.init();
        game.run();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}