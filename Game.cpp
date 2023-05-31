#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "CollisionSystem.h"

void Game::init() {
    assets = make_unique<Assets>();
    characters.push_back(new Player(Animation("main_run", 10)));
//    characters.push_back(new Enemy(Animation("eye_move", 8)));
}

void Game::update() {
    ClearBackground(RAYWHITE);
    float dt = GetFrameTime();
    spawner.update(dt);
    CollisionSystem::update(dt);
    for (auto &c: characters) {
        c->update_and_draw(dt);
    }
}

Game::~Game() {
    for (auto &c: characters) {
        delete c;
    }
}

Player *Game::get_player() {
    return dynamic_cast<Player*>(characters[0]);
}

Game game;
