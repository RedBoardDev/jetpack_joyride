#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Error/MyError.hpp"
#include "Game/Game.hpp"

namespace client {
   class Core {
        public:
            Core();
            ~Core(){};

            void run();

        private:
    };
}
