#pragma once

#include "headers.h"

class Weapon {
    float current_time = 1;
    float cooldown = 1;
    float angle = 0;
    float move_speed = 400;
    float rotation_speed = 200;
    int texture_grid_x;
    int texture_grid_y;
    Vector2 direction{0, 1};

public:
    Vector2 position{0, 0};
    int damage = 1;
    float radius = 30;

    explicit Weapon(int texture_grid_x, int texture_grid_y);

    void update_and_draw(float dt);
};


