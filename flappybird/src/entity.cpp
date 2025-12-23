#include "entity.h"
#include "raylib.h"

void init(Entity *entity, Texture2D e_tex, Vector2 pos) {
  entity->tex = e_tex;
  entity->rect = {pos.x, pos.y, (float)e_tex.width, (float)e_tex.height};
  entity->vel = {0, 0};
  entity->hitbox_offset = {0, 0, entity->rect.width * 0.65f,
                           entity->rect.height * 0.65f};
}

void apply_gravity(Entity *entity, float dt) { entity->vel.y += 400 * dt; }
void apply_velocity_y(Entity *entity, float dt) {
  entity->rect.y += entity->vel.y * dt;
}
void apply_velocity_x(Entity *entity, float dt, int move_speed) {
  entity->rect.x += move_speed * dt; 
}
void jump(Entity *entity) { entity->vel.y = -150; }
void update(Entity *entity, float dt) {
  apply_gravity(entity, dt);
  if (IsKeyPressed(KEY_SPACE))
    jump(entity);
  apply_velocity_y(entity, dt);
}

Rectangle get_hitbox(const Entity *entity) {
  return {entity->rect.x + entity->hitbox_offset.x -
              entity->hitbox_offset.width / 2,
          entity->rect.y + entity->hitbox_offset.y -
              entity->hitbox_offset.height / 2,
          entity->hitbox_offset.width, entity->hitbox_offset.height};
}
