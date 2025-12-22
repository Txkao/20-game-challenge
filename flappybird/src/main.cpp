#include <raylib.h>

#include "entity.h"

int main() {
  InitWindow(380, 640, "FlappyBird");

  SetTargetFPS(60);

  Texture2D bird_tex = LoadTexture("sprites/yellowbird-midflap.png");
  Entity bird;
  init(&bird, bird_tex);

  while (!WindowShouldClose()) {
    float dt = GetFrameTime();

    update(&bird, dt);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangleRec(bird.hit_box, RED);

    DrawTexturePro(
        bird.tex, {0, 0, (float)bird.tex.width, (float)bird.tex.height},
        bird.rect, {bird.rect.width / 2, bird.rect.height / 2}, 0, RAYWHITE);

    EndDrawing();
  }
  UnloadTexture(bird_tex);

  CloseWindow();

  return 0;
}
