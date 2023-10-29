#include "Core.hpp"

using namespace client;
using namespace game;

Core::Core()
{
}

void Core::run()
{
    Game game();
    game.MainLoop();
}
