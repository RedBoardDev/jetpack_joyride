#include "Registry.hpp"

using namespace ECS;

entity_t Registry::spawn_entity(std::size_t zIndex, bool state)
{
    entity_t entity = _next_entity_id++;
    _entity_to_index[entity] = std::make_pair(state, zIndex);

    _entities.push_back(entity);
    return entity;
}

void Registry::disableEntity(entity_t const &entity)
{
    if (_entity_to_index.find(entity) == _entity_to_index.end()) {
        throw std::runtime_error("Entity not found.");
    }
    _entity_to_index[entity].first = false;
}

void Registry::enableEntity(entity_t const &entity)
{
    if (_entity_to_index.find(entity) == _entity_to_index.end()) {
        throw std::runtime_error("Entity not found.");
    }
    _entity_to_index[entity].first = true;
}

bool Registry::isEntityEnabled(entity_t const &entity)
{
    if (_entity_to_index.find(entity) == _entity_to_index.end()) {
        throw std::runtime_error("Entity not found.");
    }
    return _entity_to_index[entity].first;
}

entity_t Registry::entity_from_index(std::size_t idx)
{
    if (idx >= _next_entity_id)
        throw std::runtime_error("Entity index out of range.");
    return _entities[idx];
}

void Registry::kill_entity(entity_t const &e)
{
    auto it = _entity_to_index.find(e);
    if (it == _entity_to_index.end())
    {
        throw std::runtime_error("Entity not found.");
    }

    if (this->hasComponent<components::ControllableComponent>(e))
        this->remove_component<components::ControllableComponent>(e);

    if (this->hasComponent<components::MovableComponent>(e))
        this->remove_component<components::MovableComponent>(e);

    if (this->hasComponent<components::ParallaxComponent>(e))
        this->remove_component<components::ParallaxComponent>(e);

    if (this->hasComponent<components::PositionComponent>(e))
        this->remove_component<components::PositionComponent>(e);

    if (this->hasComponent<components::SpriteComponent>(e))
        this->remove_component<components::SpriteComponent>(e);

    if (this->hasComponent<components::TextureRectComponent>(e))
        this->remove_component<components::TextureRectComponent>(e);

    if (this->hasComponent<components::VelocityComponent>(e))
        this->remove_component<components::VelocityComponent>(e);

    if (this->hasComponent<components::AnimationComponent>(e))
        this->remove_component<components::AnimationComponent>(e);

    if (this->hasComponent<components::ButtonComponent>(e))
        this->remove_component<components::ButtonComponent>(e);

    if (this->hasComponent<components::ScaleComponent>(e))
        this->remove_component<components::ScaleComponent>(e);

    if (this->hasComponent<components::TextComponent>(e))
        this->remove_component<components::TextComponent>(e);

    _entity_to_index.erase(it);
    if (_entity_sprite_order.count(e) > 0) {
        auto range = _entity_sprite_order.equal_range(e);
        for (auto it = range.first; it != range.second; ++it) {
            if (it->second == e) {
                _entity_sprite_order.erase(it);
                break;
            }
        }
    }
}

std::multimap<size_t, entity_t> const &Registry::get_entity_sprite_order() const {
    return _entity_sprite_order;
}
