#pragma once

#include "../ECS/Components/Components.hpp"
#include "../ECS/Registry.hpp"
#include <memory>

namespace game {
    class Factory {
        public:
        /**
         * @brief Construct a new Factory object
         *
         */
            Factory(ECS::Registry &registry);
        /**
         * @brief Destroy the Factory object
         *
         */
            ~Factory();

        private:
            ECS::Registry &_registry;
    };
}