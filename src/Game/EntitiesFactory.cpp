#include "EntitiesFactory.hpp"

using namespace game;

Factory::Factory(ECS::Registry &registry): _registry(registry)
{
    // register components
    this->_registry.register_component<ECS::components::SpriteComponent>();
    this->_registry.register_component<ECS::components::PositionComponent>();
    this->_registry.register_component<ECS::components::TextureRectComponent>();
    this->_registry.register_component<ECS::components::VelocityComponent>();
    this->_registry.register_component<ECS::components::ControllableComponent>();
    this->_registry.register_component<ECS::components::ParallaxComponent>();
    this->_registry.register_component<ECS::components::MovableComponent>();
    this->_registry.register_component<ECS::components::ScaleComponent>();
    this->_registry.register_component<ECS::components::ButtonComponent>();
    this->_registry.register_component<ECS::components::AnimationComponent>();
    this->_registry.register_component<ECS::components::ScoreComponent>();
    this->_registry.register_component<ECS::components::MusicComponent>();
    this->_registry.register_component<ECS::components::TextComponent>();
    this->_registry.register_component<ECS::components::RectangleShapeComponent>();
    this->_registry.register_component<ECS::components::LoadingBarComponent>();
    this->_registry.register_component<ECS::components::SoundComponent>();
}

Factory::~Factory()
{
}
