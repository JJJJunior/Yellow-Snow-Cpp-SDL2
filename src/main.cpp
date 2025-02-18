#include "game.h"

int main(int argc, char *args[])
{
    try
    {
        Game game;
        game.init();
        game.run();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
