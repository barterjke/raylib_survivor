#include "headers.h"
#include "Game.h"

extern Game game;

int main() {
    SetTraceLogLevel(LOG_WARNING);
    InitWindow(800, 800, "Window title");
    SetTargetFPS(60);
    game.init();
    while (!WindowShouldClose()) {
        BeginDrawing();
        game.update();
//        const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
//        DrawText("OMG! IT WORKS!", SCREEN_WIDTH / 2 - text_size.x / 2, texture_y + texture.height + text_size.y + 10, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}