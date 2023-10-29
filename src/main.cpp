// #include <signal.h>
#include "Core.hpp"

using namespace client;


int main(int ac, char **av)
{
    Core core;
    try {
        core.run();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
