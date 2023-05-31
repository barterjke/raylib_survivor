#include "Player.h"

Player::Player(Animation animation) : Character(std::move(animation)) {
    weapons.emplace_back(1, 10); // axe
    move_speed = 300;
}

void Player::update_and_draw(float dt) {
    auto move_distance = move_speed * dt;
    if (IsKeyDown(KEY_RIGHT)) {
        animation.flipped = false;
        faced_direction = {1,0};
        position.x += move_distance;
    }
    if (IsKeyDown(KEY_LEFT)) {
        faced_direction = {-1, 0};
        animation.flipped = true;
        position.x -= move_distance;
    }
    if (IsKeyDown(KEY_UP)) {
        faced_direction = {0, -1};
        position.y -= move_distance;
    }
    if (IsKeyDown(KEY_DOWN)) {
        faced_direction = {0, 1};
        position.y += move_distance;
    }

    Character::update_and_draw(dt);
    for (auto &weapon: weapons) {
        weapon.update_and_draw(dt);
    }

    //draw debug lines
    DrawRing(position, 4, 7, 0, 360, 10, damaged ? RED : BLACK);
//    DrawRectangleLinesEx(animation.get_global_boundaries(position), 3,
//                         damaged ? RED : BLACK);
}
