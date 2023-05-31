#pragma once

#include "Player.h"
#include "util.h"

struct CollisionSystem {
    constexpr static const float damage_distance = 0.4f;

    static void update(float dt);
};
