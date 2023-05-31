#include "Animation.h"
#include "Game.h"

Animation::Animation(const char *texture_name, int total_frames) : texture_name(texture_name),
                                                                   total_frames(total_frames) {

}

extern Game game;

void Animation::update_and_draw(float dt, Vector2 position) {
    current_time += dt;
    if (current_time > time_between_frames) {
        current_time -= time_between_frames;
        if (++current_frame == total_frames) {
            current_frame = 0;
        }
    }
    auto texture_rect = get_rect(false);
    texture_rect.width *= (flipped ? -1.0f : 1.0f);
    DrawTexturePro(texture(), texture_rect,
                   get_global_boundaries(position),
                   {0, 0}, 0, WHITE);
}

Texture Animation::texture() {
    return game.assets->textures_map[texture_name];
}

int Animation::get_total_frames() const {
    return total_frames;
}

Rectangle Animation::get_global_boundaries(Vector2 position) {
    auto rect = get_rect();
    rect.x = position.x - rect.width / 2.0f;
    rect.y = position.y - rect.height / 2.0f;
    return rect;
}

Rectangle Animation::get_rect(bool apply_scale) {
    float frame_width = texture().width / (float) total_frames;
    auto rect = Rectangle{frame_width * current_frame, 0,
                          frame_width, (float)texture().height};
    if (apply_scale){
        rect.width *= scale.x;
        rect.height *= scale.y;
    }
    return rect;
}
