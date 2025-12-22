#include "entity.h"
#include "raylib.h"

void init(Entity *entitiy, Texture2D e_tex) {
  entitiy->tex = e_tex;
  entitiy->rect = {190, 320, (float)e_tex.width, (float)e_tex.height};
  entitiy->vel = {0, 0};
  entitiy->hit_box = {entitiy->rect.x + (float)e_tex.width / 2,
                      entitiy->rect.y + (float)e_tex.height / 2,
                      entitiy->rect.width, entitiy->rect.height};
}

void apply_gravity(Entity *entity, float dt) { entity->vel.y += 400 * dt; }
void apply_velocity_y(Entity *entity, float dt) {
  entity->rect.y += entity->vel.y * dt;
}
void jump(Entity *entity) { entity->vel.y = -250; }
void update(Entity *entity, float dt) {
  apply_gravity(entity, dt);
  if (IsKeyPressed(KEY_SPACE))
    jump(entity);
  apply_velocity_y(entity, dt);
  update_hitbox(entity);
}
void update_hitbox(Entity *entity) {
  entity->hit_box.x = entity->rect.x - entity->rect.width / 2;
  entity->hit_box.y = entity->rect.y - entity->rect.height / 2;
  ;
}
