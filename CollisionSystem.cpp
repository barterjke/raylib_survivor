#include "CollisionSystem.h"
#include "Game.h"

extern Game game;

void CollisionSystem::update(float dt) {
    auto *player = dynamic_cast<Player *>(game.characters[0]);
    player->damaged = false;

    for (auto i = 1; i < game.characters.size(); i++) {
        auto moving_enemy = dynamic_cast<Enemy *>(game.characters[i]);
        auto direction_to_player = sub(player->position, moving_enemy->position);
        auto direction_magnitude = squared_magnitude(direction_to_player);
        if (direction_magnitude < moving_enemy->radius * moving_enemy->radius) {
            continue;
        }
        auto move_vector = scale(direction_to_player, dt * moving_enemy->move_speed / sqrt(direction_magnitude));
        auto assumed_position = add(moving_enemy->position, move_vector);
        bool can_go = true;
        float min_distance = std::numeric_limits<float>::max();
        float respective_radius;
        for (auto j = 1; j < game.characters.size(); j++) {
            auto other_enemy = dynamic_cast<Enemy *>(game.characters[j]);
            if (moving_enemy == other_enemy) continue;
            auto total_radius = moving_enemy->radius + other_enemy->radius;
            auto maybe_min_distance = distance(moving_enemy->position, other_enemy->position);
            if (maybe_min_distance < min_distance) {
                min_distance = maybe_min_distance;
                respective_radius = other_enemy->radius;
            }
            if (distance(assumed_position, other_enemy->position) < total_radius) {
                can_go = false;
            }
        }
        float move_away_scalar;
        if (!can_go) {
            if (min_distance < fmin(moving_enemy->radius, respective_radius)){
                move_away_scalar = min_distance + moving_enemy->radius;
            } else {
                move_away_scalar = abs(moving_enemy->radius + respective_radius - min_distance);
            }
        }
        moving_enemy->position = can_go ? assumed_position :
                                 add(moving_enemy->position,
                                     scale(direction_to_player, move_away_scalar / sqrt(direction_magnitude)));
    }


    for (auto i = 1; i < game.characters.size(); i++) {
        auto enemy = dynamic_cast<Enemy *>(game.characters[i]);
        enemy->damaged = false;
        if (squared_distance(player->position, enemy->position)
            < damage_distance * damage_distance) {
            player->damaged = true;
            printf("overlap\n");
        }
        for (auto &weapon: player->weapons) {
            if (squared_distance(enemy->position, weapon.position)
                < weapon.radius * weapon.radius) {
                enemy->damaged = true;
                enemy->hp -= weapon.damage;
            }
        }
    }
}
