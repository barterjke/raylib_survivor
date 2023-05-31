#include "Enemy.h"
#include "Game.h"

extern Game game;

Enemy::Enemy(Animation animation, Vector2 position)
        : Character(std::move(animation)) {
    this->position = position;
    move_speed = 50;
}

void Enemy::update_and_draw(float dt) {
    Character::update_and_draw(dt);
// draw debug lines
//    DrawRectangleLinesEx(animation.get_global_boundaries(position), 3,
//                         damaged ? RED : BLACK);
    DrawRing(position, fmax(radius - 3, 0), radius,
            0, 360, 15, damaged ? RED : BLACK);
}

