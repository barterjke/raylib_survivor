#include "Weapon.h"
#include "Game.h"

extern Game game;

Weapon::Weapon(int texture_grid_x, int texture_grid_y) :
        texture_grid_x(texture_grid_x), texture_grid_y(texture_grid_y) {
}

void Weapon::update_and_draw(float dt) {
    current_time += dt;
    position = add(position, scale(direction, move_speed * dt));
    auto texture = game.assets->textures_map["items"];
    float size = 32;
    auto rect = Rectangle{texture_grid_x * size, texture_grid_y * size,
                          size, size};
    DrawTexturePro(texture,
                   rect,
                   Rectangle{position.x, position.y, size, size},
                   {size / 2, size / 2}, angle, WHITE);
    DrawRing(position, fmax(radius - 3, 0), radius, 0, 360, 10, RED);
    angle += rotation_speed * dt;
    if (current_time > cooldown) {
        current_time -= cooldown;
        position = game.get_player()->position;
        direction = game.get_player()->faced_direction;
    }
}
