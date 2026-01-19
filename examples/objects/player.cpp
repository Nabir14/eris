#include "player.hpp"

namespace Player {
    Player::Player() {}
    
    void Player::OnLoad() {}

    void Player::OnUpdate() {}
    
    void Player::OnDraw() {
        Renderer::Renderer::Render(&this->shape, &this->mat);
        
        this->mat.setUniformValue("baseColor", 0.8902f,  0.88235f,  0.70196f);
        this->mat.setUniformValue("alpha", .5f);
    }
}