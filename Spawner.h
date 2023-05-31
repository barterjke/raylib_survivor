#pragma once
#include "headers.h"
#include "util.h"
#include "Enemy.h"

class Spawner {
    float current_time = 0;
    float cooldown = 1;
    float spawn_angle_frequency = 10;
    float distance_to_player = 300;
public:
    Spawner() = default;
    void update(float dt);
};