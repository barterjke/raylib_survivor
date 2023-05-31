#pragma once
#include "headers.h"
#include "Assets.h"
#include "Character.h"
#include "Spawner.h"
#include "Player.h"

class Game {
public:
    unique_ptr<Assets> assets;
    vector<Character *> characters;
    Spawner spawner;

    void init();

    void update();

    Player * get_player();

    ~Game();
};