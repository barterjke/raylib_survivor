#pragma once

#include "headers.h"

class Animation {
    string texture_name;
    int total_frames;
    int current_frame = 0;
    float current_time = 0;
    float time_between_frames = 0.1;
    Vector2 scale{3, 3};
public:
    int get_total_frames() const;

    bool flipped = false;

    Animation(const char *texture_name, int frames);

    Rectangle get_global_boundaries(Vector2 position);

    Rectangle get_rect(bool apply_scale = true);

    Animation() = default; // maybe remove

    void update_and_draw(float dt, Vector2 position);

    Texture texture();
};
