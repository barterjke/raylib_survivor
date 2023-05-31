#pragma once

#include "headers.h"
#include "util.h"
#include "Character.h"

class Enemy : public Character {
public:
    float radius = 20;
    int hp = 2;
    bool damaged = false;

    Enemy(Animation animation, Vector2 position);

    void update_and_draw(float dt) override;
};