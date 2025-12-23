#include <cstdlib>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "entity.h"

int main() {
  InitWindow(360, 640, "FlappyBird");

  srand(time(NULL));
  SetTargetFPS(60);

  Texture2D bird_tex = LoadTexture("sprites/yellowbird-midflap.png");
  Texture2D pipe_tex = LoadTexture("sprites/pipe-green.png");
  Entity bird;
  Entity pipes[2];
  init(&bird, bird_tex, {180, 320});
  float pipe_offset = -80;
  int rand_y = rand() % (380 - 320 + 1) + 320;
  for (int i = 0; i < 2; i++) {
    init(&pipes[i], pipe_tex, {360, rand_y + (i * pipe_offset)});
  }

  while (!WindowShouldClose()) {
    rand_y = rand() % (380 - 320 + 1) + 320;
    float dt = GetFrameTime();

    update(&bird, dt);
    for (int i = 0; i < 2; i++) {
      apply_velocity_x(&pipes[i], dt, -100);
      if (pipes[i].rect.x < -40) {
        pipes[i].rect.x = 360;
        pipes[i].rect.y = (rand_y + (i * pipe_offset));
      }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Rectangle hitbox = get_hitbox(&bird);
    // DrawRectangleRec(hitbox, RED);

    DrawTexturePro(
        bird.tex, {0, 0, (float)bird.tex.width, (float)bird.tex.height},
        bird.rect, {bird.rect.width / 2, bird.rect.height / 2}, 0, RAYWHITE);
    DrawTexturePro(
        pipes[0].tex,
        {0, 0, (float)pipes[0].tex.width, (float)pipes[0].tex.height},
        pipes[0].rect, {pipes[0].rect.width / 2, 0}, 0, RAYWHITE);
    DrawTexturePro(
        pipes[1].tex,
        {0, 0, (float)pipes[1].tex.width, (float)pipes[1].tex.height},
        pipes[1].rect, {pipes[1].rect.width / 2, 0}, 180, RAYWHITE);

    EndDrawing();
  }
  UnloadTexture(bird_tex);

  CloseWindow();

  return 0;
}
