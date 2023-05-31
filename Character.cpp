#include "Character.h"

void Character::update_and_draw(float dt) {
    animation.update_and_draw(dt, position);
}

Character::Character(Animation animation) : animation(std::move(animation)) {

}