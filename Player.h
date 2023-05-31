#pragma once

#include "headers.h"
#include "Character.h"
#include "Weapon.h"

class Player : public Character {
public:
    vector<Weapon> weapons;
    bool damaged = false;
    Vector2 faced_direction{1,0};

    explicit Player(Animation animation);

    void update_and_draw(float dt) override;
};
