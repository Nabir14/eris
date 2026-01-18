#include "player.hpp"

namespace Player {
    Player::Player() {}
    
    void Player::OnLoad() {}
    void Player::OnUpdate() {}
    
    void Player::OnDraw() {
        Renderer::Renderer::Render(&this->shape, &this->mat);
    }
}