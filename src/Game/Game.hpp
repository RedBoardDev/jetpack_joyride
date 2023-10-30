#pragma once

#include "../Core.hpp"
#include "./Loader/Loader.hpp"
#include "../Utils.hpp"
#include "../ECS/Registry.hpp"
#include "EntitiesFactory.hpp"
#include "EntityManager/MenuManager.hpp"
#include "EntityManager/EntityManager.hpp"

namespace game {
    enum Colors {
        RED = 1,
        GREEN,
        BLUE,
        YELLOW,
        PURPLE,
        CYAN,
        WHITE
    };
    class Game: public EntityManager {
        public:
        /**
         * @brief Construct a new Game object
         *
         */
            Game();
        /**
         * @brief Destroy the Game object
         *
         */
            ~Game();
        /**
         * @brief function who's looping on the window and call everythings
         *
         * @return int
         */
            int MainLoop();
        /**
         * @brief update data for entities
         *
         */

            enum gameState {
                MENU,
                MATCHMAKING,
                GAME,
                ENDGAME
            };

        private:
            sf::RenderWindow _window;

            Loader _manager;
            ECS::Registry ecs;
            Factory _factory;
            MenuManager _menuManager;

            long _lastTime;
            int eventMemory;
            gameState _gameState;
    };
}
