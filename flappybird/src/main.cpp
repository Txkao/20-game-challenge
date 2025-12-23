#include <cstdlib>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "entity.h"

int main() {
  InitWindow(288, 512, "FlappyBird");

  srand(time(NULL));
  SetTargetFPS(60);

  Texture2D bird_tex = LoadTexture("sprites/yellowbird-midflap.png");
  Texture2D pipe_tex = LoadTexture("sprites/pipe-green.png");
  Texture2D ground_tex = LoadTexture("sprites/base.png");
  Texture2D background = LoadTexture("sprites/background-day.png");
  Entity bird;
  Entity pipes[2];
  Entity ground[2];
  init(&bird, bird_tex, {180, 288});
  float pipe_offset = -80;
  int rand_y = rand() % (300 - 160 + 1) + 160;
  for (int i = 0; i < 2; i++) {
    init(&pipes[i], pipe_tex, {288, rand_y + (i * pipe_offset)});
  }
  for (int i = 0; i < 2; i++) {
    init(&ground[i], ground_tex,
         {i * (float)ground_tex.width, 512 - (float)ground_tex.height});
  }

  while (!WindowShouldClose()) {
    rand_y = rand() % (300 - 160 + 1) + 160;
    float dt = GetFrameTime();

    update(&bird, dt);
    for (int i = 0; i < 2; i++) {
      apply_velocity_x(&pipes[i], dt, -100);
      if (pipes[i].rect.x < -40) {
        pipes[i].rect.x = 288;
        pipes[i].rect.y = (rand_y + (i * pipe_offset));
      }
    }
    for (int i = 0; i < 2; i++) {
      apply_velocity_x(&ground[i], dt, -100);
      if (ground[i].rect.x <= -ground_tex.width) {
        ground[i].rect.x = ground[i].rect.x + (ground_tex.width * 2);
      }
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Rectangle hitbox = get_hitbox(&bird);
    // DrawRectangleRec(hitbox, RED);

    DrawTexture(background, 0, 0, RAYWHITE);

    DrawTexturePro(
        bird.tex, {0, 0, (float)bird.tex.width, (float)bird.tex.height},
        bird.rect, {bird.rect.width / 2, bird.rect.height / 2}, 0, RAYWHITE);
    for (int i = 0; i < 2; i++) {
      DrawTexturePro(
          pipes[i].tex,
          {0, 0, (float)pipes[i].tex.width, (float)pipes[i].tex.height},
          pipes[i].rect, {pipes[i].rect.width / 2, 0}, i * 180, RAYWHITE);
    }
    for (int i = 0; i < 2; i++) {
      DrawTexturePro(
          ground[i].tex,
          {0, 0, (float)ground[i].tex.width, (float)ground[i].tex.height},
          ground[i].rect, {0, 0}, 0, RAYWHITE);
    }

    EndDrawing();
  }
  UnloadTexture(bird_tex);
  UnloadTexture(pipe_tex);
  UnloadTexture(ground_tex);
  UnloadTexture(background);

  CloseWindow();

  return 0;
}
