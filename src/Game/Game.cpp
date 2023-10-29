#include "./Game.hpp"
#include "../ECS/Components/Components.hpp"
#include "../ECS/Systems/Systems.hpp"
#include <iomanip>

using namespace game;
using entity_t = std::size_t;
using namespace TypesLitterals;

Game::Game() :
    _manager(Loader()),
    _factory(Factory(ecs)),
    _menuManager(ecs),
{
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    try {
        // this->_manager.loadTexture(client::getAssetPath("entity/Pixels/BlackPixel.png"), Loader::toLoad::BlackPixel);

        // this->_manager.loadFont(client::getAssetPath("fonts/arial.ttf"), Loader::toLoad::Arial);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    if (mode.isValid()) {
        this->_window.create(mode, "Jetpack Joyride", sf::Style::Fullscreen);
    } else {
        this->_window.create(sf::VideoMode(mode.width, mode.height), "Jetpack Joyride");
    }

    this->_window.setFramerateLimit(120);
    this->_gameState = gameState::MENU;
}

Game::~Game()
{
}

int Game::MainLoop()
{
    while (this->_window.isOpen()) {
        long currentTime = NOW;
        float deltaTime = (currentTime - this->_lastTime) / 1.0f;
        this->_lastTime = currentTime;

        // ALL SYSTEMS CALL HERE
        ECS::systems::ControllableSystem().update(this->ecs, this->_entityEvents, this->_window, this->eventMemory);
        ECS::systems::PositionSystem().update(this->ecs, this->topLeftOffeset);
        ECS::systems::AnimationSystem().update(this->ecs, deltaTime);
        ECS::systems::ParallaxSystem().update(this->ecs, deltaTime, this->topLeftOffeset);
        ECS::systems::MovableSystem().update(this->ecs, this->_entityPositions, this->topLeftOffeset);
        ECS::systems::ScaleSystem().update(this->ecs);
        ECS::systems::TextSystem().update(this->ecs, this->_texts);
        this->_window.clear();

        // DRAW SYSTEM CALL HERE
        ECS::systems::DrawSystem().update(this->ecs, this->_window);
        this->_window.display();
    }
    return 0;
}
