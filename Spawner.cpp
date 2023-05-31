#include "Spawner.h"
#include "Game.h"

extern Game game;

void Spawner::update(float dt) {
    current_time += dt;
    if (current_time > cooldown) {
        current_time -= cooldown;
        auto player_pos = game.characters[0]->position;
        float angle = GetTime() * spawn_angle_frequency * pi / 180;
        auto enemy_pos = add(player_pos,
                scale(Vector2{sin(angle), cos(angle)}, distance_to_player));
        game.characters.push_back(
                new Enemy(Animation("eye_move", 8), enemy_pos));
    }
}