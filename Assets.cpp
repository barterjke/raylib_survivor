#include "Assets.h"

Assets::Assets() {
    string to_load[] = {"main_run", "main_idle", "eye_move", "items", "BRICK_1A", "BRICK_1B"};
    for (auto &name: to_load) {
        textures_map[name] = LoadTexture(("../assets/" + name + ".png").c_str());
    }
}
