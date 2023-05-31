#pragma once

#include <utility>

#include "headers.h"
#include "Animation.h"

class Character {

protected:
    Animation animation;
public:
    Vector2 position = {0, 0};
    float move_speed = 100;

    virtual void update_and_draw(float dt);

    explicit Character(Animation animation);

    Character() = default; //maybe remove?
};


